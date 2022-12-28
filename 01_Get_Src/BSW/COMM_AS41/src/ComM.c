/* PRQA S 8014, 8114, 8314, 8414, 8614 ++*/
/* !Deviation: [8014] [8114] [8314] [8614] Violates VNR on file naming rules
    because file names are imposed by AutOSAR requirements */
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : ComM                                                    */
/* !Description     : Communication Manager Module                            */
/*                                                                            */
/* !Module          : ComM                                                    */
/*                                                                            */
/* !File            : ComM.c                                                  */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/04-ComM/02$*/
/* $Revision::   1.88     $$Author::   knasr          $$Date::   Jun 27 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file ComM.c
*
* \par
*   Internals of the module ComM.
*   This file contains the internals of the module ComM. */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module ComM
* This is the grouping of the ComM module members.
* \{
*/
/******************************************************************************/


/* !Deviation: [0857] Under certain configurations, ComM may have more than
    1024 definitions, so the compiler should be able to handle more than 1024
    definitions. */

/* PRQA S 0857 ++ */
#include "ComM.h"



#include "ComM_BusSm.h"
#if (ComM_bCOMM_DCM_ENABLED == TRUE)
#include "ComM_Dcm.h"
#include "Dcm_Cbk.h"
#endif /* ComM_bCOMM_DCM_ENABLED */
#include "ComM_Nm.h"
#include "ComM_EcuMBswM.h"
#include "SchM_ComM.h"
#if (ComM_bMODE_LIMIT_ENABLE == TRUE || ComM_bPNC_SUPPORT == TRUE)
#include "NvM.h"
#endif /* ComM_bMODE_LIMIT_ENABLE || ComM_bPNC_SUPPORT */

#if (ComM_bRTE_USED == STD_ON)
#include "Rte_ComM.h"
#elif (ComM_bRTE_USED == STD_OFF)
#include "User_ComM.h"
#endif

#if ((ComM_bANY_FULL_CHANNEL == TRUE)||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
#include "Nm.h"
#endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */


#if (ComM_bCAN_USED == TRUE)
#include "CanSM_ComM.h"
#endif /* ComM_bCAN_USED */

#if (ComM_bLIN_USED == TRUE)
#include "LinSM.h"
#endif /* ComM_bLIN_USED */

#if (ComM_bFR_USED == TRUE)
#include "FrSM.h"
#endif /* ComM_bFR_USED */

#if (ComM_bETH_USED == TRUE)
#include "EthSM.h"
#endif /* ComM_bETH_USED */

#include "BswM_ComM.h"
#include "ComM_Internal.h"


#if (ComM_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* ComM_bDEV_ERROR_DETECT */


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define u8TRANS_NO_TO_FULL      (7)
#define u8TRANS_SILENT_TO_FULL  (8)
#define u8TRANS_FULL_TO_SILENT  (9)
#define u8TRANS_SILENT_TO_NO    (10)
#define u8TRANS_FULL_TO_NO      (11)
#define u8TRANS_NO_TO_FULL_NR   (12)
#define u8TRANS_SIL_TO_FULL_NR  (13)

#define u8NONE                  0
#define u8PASSIVE_WAKEUP        1
#define u8ACTIVE_WAKEUP         2
#define u8ENTER_READY_SLEEP     3
#define u8ENTER_NO_COMM         4

#define u16INH_COUNTER_MAX      65535U

/**********************      Version Checking       ***************************/
#define u8C_SW_MAJOR_VERSION    3
#define u8C_SW_MINOR_VERSION    0
/******************************************************************************/
/*                      Implementation version checking                       */
/******************************************************************************/
/*                           Intra-Module Checking                            */
/******************************************************************************/
#if (u8C_SW_MAJOR_VERSION != COMM_SW_MAJOR_VERSION)
    #error Incompatible ComM SW major version between C & H files.
#endif

#if (u8C_SW_MINOR_VERSION != COMM_SW_MINOR_VERSION)
    #error Incompatible ComM SW minor version between C & H files.
#endif
/******************************************************************************/
/*                           Inter-Module Checking                            */
/******************************************************************************/

#if (ComM_bINTER_MOD_VER_CHECK == STD_ON)

#if (COMM_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)
    #error Compiler AR RELEASE MAJOR VERSION is not compatible with ComM AR \
           RELEASE MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < COMPILER_AR_RELEASE_MINOR_VERSION)
    #error Compiler AR RELEASE MINOR VERSION is not compatible with ComM AR \
           RELEASE MINOR VERSION.
#endif

#if (COMM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
    #error Std AR RELEASE MAJOR VERSION is not compatible with ComM AR \
           RELEASE MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < STD_AR_RELEASE_MINOR_VERSION)
    #error Std AR RELEASE MINOR VERSION is not compatible with ComM AR \
           RELEASE MINOR VERSION.
#endif

#if (COMM_AR_RELEASE_MAJOR_VERSION != MEM_AR_RELEASE_MAJOR_VERSION)
    #error MemMap AR RELEASE MAJOR VERSION is not compatible with ComM AR \
           RELEASE MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < MEM_AR_RELEASE_MINOR_VERSION)
    #error MemMap AR RELEASE MINOR VERSION is not compatible with ComM AR \
           RELEASE MINOR VERSION.
#endif

#if (COMM_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)
    #error Platform AR RELEASE MAJOR VERSION is not compatible with ComM AR \
           RELEASE MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < PLATFORM_AR_RELEASE_MINOR_VERSION)
    #error Platform AR RELEASE MINOR VERSION is not compatible with ComM AR \
           RELEASE MINOR VERSION.
#endif

#if (ComM_bMODE_LIMIT_ENABLE == TRUE)

#if (COMM_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION)
    #error NvM AR RELEASE MAJOR VERSION is not compatible with ComM AR RELEASE \
           MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < NVM_AR_RELEASE_MINOR_VERSION)
    #error NvM AR RELEASE MINOR VERSION is not compatible with ComM AR RELEASE \
           MINOR VERSION.
#endif

#endif /* ComM_bMODE_LIMIT_ENABLE */

#if ((ComM_bANY_FULL_CHANNEL == TRUE)||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
#if (COMM_AR_RELEASE_MAJOR_VERSION != NM_AR_RELEASE_MAJOR_VERSION)
    #error Nm AR RELEASE MAJOR VERSION is not compatible with ComM AR RELEASE \
           MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION != NM_AR_RELEASE_MINOR_VERSION)
    #error Nm AR RELEASE MINOR VERSION is not compatible with ComM AR RELEASE \
           MINOR VERSION.
#endif
#endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */

#if (ComM_bDEV_ERROR_DETECT == STD_ON)

#if (COMM_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
    #error Det AR RELEASE MAJOR VERSION is not compatible with ComM AR RELEASE \
           MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < DET_AR_RELEASE_MINOR_VERSION)
    #error Det AR RELEASE MINOR VERSION is not compatible with ComM AR RELEASE \
           MINOR VERSION.
#endif

#endif /* ComM_bDEV_ERROR_DETECT */

#if (ComM_bCAN_USED == TRUE)
#if (COMM_AR_RELEASE_MAJOR_VERSION != CANSM_AR_RELEASE_MAJOR_VERSION)
    #error CanSM AR RELEASE MAJOR VERSION is not compatible with ComM AR \
           RELEASE MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < CANSM_AR_RELEASE_MINOR_VERSION)
    #error CanSM AR RELEASE MINOR VERSION is not compatible with ComM AR \
           RELEASE MINOR VERSION.
#endif
#endif /* ComM_bCAN_USED */

#if (ComM_bLIN_USED == TRUE)
#if (COMM_AR_RELEASE_MAJOR_VERSION != LINSM_AR_RELEASE_MAJOR_VERSION)
    #error LinSM AR RELEASE MAJOR VERSION is not compatible with ComM AR \
           RELEASE MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < LINSM_AR_RELEASE_MINOR_VERSION)
    #error LinSM AR RELEASE MINOR VERSION is not compatible with ComM AR \
           RELEASE MINOR VERSION.
#endif
#endif /* ComM_bLIN_USED */

#if (ComM_bFR_USED == TRUE)
#if (COMM_AR_RELEASE_MAJOR_VERSION != FRSM_AR_RELEASE_MAJOR_VERSION)
    #error FrSM AR RELEASE MAJOR VERSION is not compatible with ComM AR RELEASE\
           MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < FRSM_AR_RELEASE_MINOR_VERSION)
    #error FrSM AR RELEASE MINOR VERSION is not compatible with ComM AR RELEASE\
           MINOR VERSION.
#endif
#endif /* ComM_bFR_USED */

#if (ComM_bETH_USED == TRUE)
#if (COMM_AR_RELEASE_MAJOR_VERSION != ETHSM_AR_RELEASE_MAJOR_VERSION)
    #error EthSM AR RELEASE MAJOR VERSION is not compatible with ComM AR \
           RELEASE MAJOR VERSION.
#endif
#if (COMM_AR_RELEASE_MINOR_VERSION < ETHSM_AR_RELEASE_MINOR_VERSION)
    #error EthSM AR RELEASE MINOR VERSION is not compatible with ComM AR \
           RELEASE MINOR VERSION.
#endif
#endif /* ComM_bETH_USED */

#endif /* #if (ComM_bINTER_MOD_VER_CHECK == STD_ON) */

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !Deviation: [3453] Violates MISRA rule 93: "A function should be used in
    preference to a function-like macro." but these function-like macros are
    only to abbreviate long function calls to make the code more readable and to
    avoid breaking the 80 characters mark.
*/
/* !Deviation: [3456] "parameter X will be evaluated more than once when this
    macro is used", the only danger this imposes is when the argument is
    something like i++, but since there is another rule that inhibits this then
    no harm will be done.
*/
/* PRQA S 3453, 3456 ++*/


#define u8CH_USR_REF_SIZE(CH)    ComM_akudteUsersPerChannel[CH].ComM_ku8Size
#define pu8CH_USR_REF_ARRAY(CH)  \
    ComM_akudteUsersPerChannel[CH].ComM_kpku8UsersArray

#define u16USR_CH_REF_SIZE(User)  \
    ComM_akudteChannelsPerUser[User].ComM_ku16Size
#define pu8USR_CH_REF_ARRAY(User) \
    ComM_akudteChannelsPerUser[User].ComM_kpku8ChannelsArray

#define akpfu8MSI_ARRAY  ComM_akpfu8eUserModeMSIArray

#define bCHK_LIMNOCOM_GC ((ComM_u8eECUGClassification & 0x02) >> 1)
#define bCHK_NOWAKEUP_GC (ComM_u8eECUGClassification % 0x02)


#if (ComM_bPNC_SUPPORT == TRUE)

#define u16PNC_TX_SIG_REF_SIZE(SIG)  \
    ComM_akudteTxSignalsPerPnc[SIG].ComM_ku16Size
#define u16PNC_TX_SIG_REF_ARRAY(SIG) \
    ComM_akudteTxSignalsPerPnc[SIG].ComM_kpku16SigsArray

#define u8COMM_PNC_ID(ku8PncIdInd)      ComM_aku8ePncId[ku8PncIdInd]

#if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)

#define pu8TX_AGG                     ComM_au8eTxAgg
#define ComM_au8eTxAgg(IND)                 ComM_au8eTxAgg[IND]
#if (ComM_bPNC_GW_ENABLED == TRUE)
#define pu8ERA_GW_TX_AGG                ComM_au8eTxERAAgg
#endif /* ComM_bPNC_GW_ENABLED */

#elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)

#define pu8TX_AGG                     &ComM_u8TxAgg
#if (ComM_bPNC_GW_ENABLED == TRUE)
#define pu8ERA_GW_TX_AGG                &ComM_u8eTxERAAgg
#endif /* ComM_bPNC_GW_ENABLED */

#endif /*ComM_u8NO_SIZE_OF_SIG_ARR*/

#endif /* ComM_bPNC_SUPPORT */

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/******************************************************************************/
/*! \Description Inhibition Counter (Inhibited Requests)
    \Range 0..65535
 */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
#define COMM_START_SEC_VAR_16
/* PRQA S 838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */

static VAR(uint16, COMM_VAR) ComM_u16InhibitCounter;

#define COMM_STOP_SEC_VAR_16
/* PRQA S 838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */
#endif /* ComM_bMODE_LIMIT_ENABLE */
/******************************************************************************/
/*! \Description Variable to hold ComM Initialisation status.
    \Range COMM_UNINIT, COMM_INIT
 */

/* !Deviation: [0857] Under certain configurations, ComM may have more than
1024 definitions, so the compiler should be able to handle more than 1024
definitions. */

/* PRQA S 0857 ++ */
#define COMM_START_SEC_VAR_8
/* PRQA S 0857 -- */
/* PRQA S 838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */

VAR(ComM_InitStatusType, COMM_VAR_POWER_ON_INIT)
                            ComM_udteInitStatus = COMM_UNINIT;
#define COMM_STOP_SEC_VAR_8
/* PRQA S 838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */




#define COMM_START_SEC_VAR_UNSPECIFIED
/* PRQA S 838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */
/******************************************************************************/
/*! \Description Static Array to hold whether channel requesters has changed or
                 not.                                                         \n
    \Range TRUE, FALSE */
#if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
VAR(boolean, COMM_VAR)
        ComM_abeChannelReqsUpdated[ComM_u16NO_OF_CHANNELS];
#endif /* ComM_bANY_FCOM_SRI_ENABLE */

#if (ComM_bMODE_LIMIT_ENABLE == TRUE || ComM_bPNC_SUPPORT == TRUE)
/******************************************************************************/
/*! \Description NvM Ram block array */
VAR(uint8, COMM_VAR) ComM_au8eRamBlk[ComM_u8RAM_BLOCK_SIZE];

#endif /* (ComM_bMODE_LIMIT_ENABLE || ComM_bPNC_SUPPORT) */

#if (ComM_bMODE_LIMIT_ENABLE == TRUE)

#if (ComM_bWAKEUP_INH_ENABLE == TRUE)
/******************************************************************************/
/*! \Description Static Array to hold WakeUp inhibition status, see
                 ComMNoWakeUp.                                                \n
    \Range TRUE, FALSE */
VAR(boolean, COMM_VAR)
        ComM_abeWakeUpInibitStatus[ComM_u16NO_OF_CHANNELS];
#endif /* ComM_bWAKEUP_INH_ENABLE */

/******************************************************************************/
/*! \Description Static Array to hold NoCom Limitation status, see ComMNoCom. \n
    \Range TRUE, FALSE */
VAR(boolean, COMM_VAR)
        ComM_abeLimitToNoComStatus[ComM_u16NO_OF_CHANNELS];

/******************************************************************************/
/*! \Description Static UINT8 to hold ECUGroupClassification.                 \n
    \Range 0, 1, 2, 3
 */
VAR(ComM_InhibitionStatusType, COMM_VAR) ComM_u8eECUGClassification;
#endif /* ComM_bMODE_LIMIT_ENABLE */

#if ((ComM_bPNC_SUPPORT == TRUE) && (ComM_bPNC_GW_ENABLED == TRUE))
/******************************************************************************/
/*! \Description Static ComM_abChGwPncReq to hold if the Channel is requested
                 by GW PNC or not. \n
    \Range TRUE, FALSE
 */
static VAR(boolean, COMM_VAR) ComM_abChGwPncReq[ComM_u16NO_OF_CHANNELS];

#endif /* ((ComM_bPNC_SUPPORT) && (ComM_bPNC_GW_ENABLED)) */

#if (ComM_bPNC_SUPPORT == TRUE)
/******************************************************************************/
/*! \Description Static UINT16 to hold PNC's timer.                 \n
    \Range TRUE, FALSE
 */
static VAR(uint16, COMM_VAR) ComM_au16PncTimer[ComM_u8NO_OF_PNCS];

/******************************************************************************/
/*! \Description Static boolean to hold COMM_PNC_ENABLED flag.                \n
    \Range TRUE, FALSE
 */
VAR(boolean, COMM_VAR) ComM_bePncEnabled;

/******************************************************************************/
/*! \Description Static ComM_PncModeType to hold PNC's state.                 \n
    \Range PNC_REQUESTED, PNC_READY_SLEEP, PNC_PREPARE_SLEEP,\n
    PNC_NO_COMMUNICATION, PNC_FULL_COMMUNICATION
 */
static VAR(ComM_PncModeType, COMM_VAR) ComM_au8PncState[ComM_u8NO_OF_PNCS];

#if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
/******************************************************************************/
/*! \Description Static ComM_u8SignalArrayType to hold the received aggregated
                 signal.         \n
    \Range 0..255
 */
VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_au8eAggregSignal;
/******************************************************************************/
/*! \Description Static ComM_u8SignalArrayType to hold the aggregated signal to
                 be transmitted \n
    \Range 0..255
 */
VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_au8eTxAgg;


#if (ComM_bPNC_GW_ENABLED == TRUE)
/******************************************************************************/
/*! \Description Static ComM_u8SignalArrayType to hold the received aggregated
                 signal for ERA signals.         \n
    \Range 0..255
 */
VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_au8eAggregERASig;

/******************************************************************************/
/*! \Description Static ComM_u8SignalArrayType to hold the aggregated signal to
                 be transmitted \n
    \Range 0..255
 */
VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_au8eTxERAAgg;

#endif /* ComM_bPNC_GW_ENABLED */


#elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
/******************************************************************************/
/*! \Description Static UINT8 to hold the received aggregated signal.         \n
    \Range 0..255
 */
VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_u8eAggregSignal;
/******************************************************************************/
/*! \Description Static UINT8 to hold the aggregated signal to be transmitted \n
    \Range 0..255
 */
static VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_u8TxAgg;

#if (ComM_bPNC_GW_ENABLED == TRUE)
/******************************************************************************/
/*! \Description Static ComM_u8SignalArrayType to hold the received aggregated
                 signal for ERA signals.         \n
    \Range 0..255
 */
VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_u8eAggregERASig;

/*! \Description Static ComM_u8SignalArrayType to hold the aggregated signal to
                 be transmitted \n
    \Range 0..255
 */
VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_u8eTxERAAgg;
#endif /* ComM_bPNC_GW_ENABLED */
#endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
#endif /* ComM_bPNC_SUPPORT */


#if (ComM_bCOMM_DCM_ENABLED == TRUE)
/******************************************************************************/
/*! \Description Static Array to hold DCM active diagnostic status.           \n
    \Range TRUE, FALSE */
static VAR(boolean, COMM_VAR)
        ComM_abDCMActiveDiagnostic[ComM_u16NO_OF_CHANNELS];

#endif /* ComM_bCOMM_DCM_ENABLED */

/******************************************************************************/
/*! \Description Static Array to hold CommunicationAllowed Flags.             \n
    \Range TRUE, FALSE */
static VAR(boolean, COMM_VAR)
        ComM_abCommunicationAllowed[ComM_u16NO_OF_CHANNELS];

/******************************************************************************/
/*! \Description Static Array to hold State Machines' States.                 \n
    \Range COMM_NO_COM_NO_PENDING_REQUEST, COMM_NO_COM_REQUEST_PENDING,
           COMM_FULL_COM_NETWORK_REQUESTED, COMM_FULL_COM_READY_SLEEP,
           COMM_SILENT_COM, u8TRANS_NO_TO_FULL, u8TRANS_FULL_TO_NO,
           u8TRANS_FULL_TO_SILENT, u8TRANS_SILENT_TO_NO, u8TRANS_SILENT_TO_FULL
 */
static VAR(ComM_StateType, COMM_VAR)
        ComM_au8StateMachines[ComM_u16NO_OF_CHANNELS];

/******************************************************************************/
/*! \Description Static Array to hold transition flags, these flags assist in
                 the realisation of ComM behaviour for each ComMNmVariant and
                 the realization of the passive wake up capability.           \n
    \Range u8NONE, u8NONE, u8PASSIVE_WAKEUP, u8ACTIVE_WAKEUP,
           u8ENTER_READY_SLEEP, u8ENTER_NO_COMM */
static VAR(uint8, COMM_VAR)
        ComM_au8WakeUpSleepStatus[ComM_u16NO_OF_CHANNELS];

/******************************************************************************/
/*! \Description Static Array to hold user request status.                    \n
    \Range TRUE, FALSE */
static VAR(boolean, COMM_VAR)
        ComM_abUserRequestStatus[ComM_u8NO_OF_USERS];

#define COMM_STOP_SEC_VAR_UNSPECIFIED
/* PRQA S 838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */

#define COMM_START_SEC_CODE
/* PRQA S 838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */
/******************************************************************************/
/*                                 Declarations                               */
/******************************************************************************/

#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
/******************************************************************************/
/*! \Description Function to increment the inhibition counter, this has been
                 ported to a function so that this function can manage not to
                 increment it out of bounds and to manage the critical section
                 protection as well.
*******************************************************************************/
static FUNC(void, COMM_CODE) vidIncrInhCounter(void);
#endif /* ComM_bMODE_LIMIT_ENABLE */


#if ((ComM_bANY_FULL_CHANNEL == TRUE)||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
/******************************************************************************/
/*! \Description Function to start the transition to COMM_FULL_COMMUNICATION
                 based on a ComM_Nm_NetworkStartIndication() if the channel was
                 not already in COMM_FULL_COMMUNICATION nor was it in a
                 transient state to COMM_FULL_COMMUNICATION. \n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in
                 ComM_Nm_NetworkStartIndication().
    \param[in]  ku8Channel The Channel for which the transition will be started.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
*******************************************************************************/
static FUNC(void, COMM_CODE) vidGoToFCom(const NetworkHandleType ku8Channel);
#endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */


/******************************************************************************/
/*! \Description Function to get a user's ComMode, to be used in notification
                 later.                                                       \n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in vidDoNotify().
    \param[in]  ku8User The user for which the ComMode will be retrieved.     \n
                \Range 0..(ComM_u8NO_OF_USERS-1)                              \n
                \Unit ComM_UserHandleType
    \return     COMM_FULL_COMMUNICATION, COMM_SILENT_COMMUNICATION,
                COMM_NO_COMMUNICATION.
*******************************************************************************/
static FUNC(ComM_ModeType, COMM_CODE) u8GetUserComMode (
        const ComM_UserHandleType ku8User);


/******************************************************************************/
/*! \Description Function to get, for a channel, the current or future ComMode
                 -in case the channel was in a transient sub-state- to be used
                 in detecting conflicts in ComM_BusSM_ModeIndication().       \n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in
                 ComM_BusSM_ModeIndication().
    \param[in]  ku8Channel The Channel for which the ComMode will be retrieved.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \return     COMM_FULL_COMMUNICATION, COMM_SILENT_COMMUNICATION,
                COMM_NO_COMMUNICATION.
*******************************************************************************/
static FUNC(ComM_ModeType, COMM_CODE) u8GetChannelFutComMode(
        const NetworkHandleType ku8Channel);

#if ((ComM_bANY_FULL_CHANNEL == TRUE)||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
/******************************************************************************/
/*! \Description Function to handle receiving a ComM_BusSM_ModeIndication()
                 with a COMM_FULL_COMMUNICATION in a transient state to
                 COMM_FULL_COMMUNICATION.                                     \n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in
                 ComM_BusSM_ModeIndication().
    \param[in]  ku8Channel The Channel for which the transition will be started.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoBusMITransToFull(
                                const NetworkHandleType ku8Channel);
#endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */

/******************************************************************************/
/*! \Description Function to handle notifications of ComMode changes of a
                 channel, these notifications are to Users, BswM, and Dcm.
    \param[in]  ku8Channel The Channel for which notifications will be handled.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  ku8ComMode The ComMode to which the channel has switched.     \n
                \Range COMM_FULL_COMMUNICATION, COMM_SILENT_COMMUNICATION,
                COMM_NO_COMMUNICATION                                         \n
                \Unit ComM_ModeType
    \Trace_To   ComM-CDD-0111(0)
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoNotify(const NetworkHandleType ku8Channel,
                                         const ComM_ModeType ku8ComMode);


#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
/******************************************************************************/
/*! \Description Function to handle clearing a faulty user request in case a
                 channel has been moved to COMM_NO_COMMUNICATION due to a
                 ComMNoCom limitation.
                 \note A faulty request is a user's request when all of the
                       channels assigned to that user has been moved to
                       COMM_NO_COMMUNICATION due to a ComMNoCom limitation.
    \param[in]  ku8Channel The Channel for which faulty requests shall be
                cleared.                                                      \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
*******************************************************************************/
static FUNC(void, COMM_CODE) vidClearFaultyRequests(
                             const NetworkHandleType ku8Channel);
#endif /* ComM_bMODE_LIMIT_ENABLE */


/******************************************************************************/
/*! \Description Function to handle COMM_FULL_COMMUNICATION request by a user.\n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in ComM_RequestComMode().
    \param[in]  ku8User The Channel for which the sub-state will be retrieved.\n
                \Range 0..(ComM_u8NO_OF_USERS-1)                              \n
                \Unit ComM_UserHandleType
    \return     E_OK, E_NOT_OK, COMM_E_MODE_LIMITATION
*******************************************************************************/
static FUNC(Std_ReturnType, COMM_CODE) u8HandleFComReq(
                                       const ComM_UserHandleType ku8User);


#if (ComM_bANY_FULL_CHANNEL == TRUE)
/******************************************************************************/
/*! \Description Function to handle the COMM_FULL_COM_NETWORK_REQUESTED
                 sub-state of a channel whose ComMNmVariant is FULL.          \n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in vidManageFULLSM().
    \param[in]  ku8Channel The Channel for which the sub-states will be managed.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  kbLimToNoCom Indication whether a ComMNoCom limitation is active
                or not.                                                       \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbActiveUR Indication whether or not there is an active user
                request.                                                      \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoFullComNWFULL(
                                        const NetworkHandleType ku8Channel,
                                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                        const boolean kbLimToNoCom,
                                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                                        const boolean kbActiveUR);


/******************************************************************************/
/*! \Description Function to handle the COMM_FULL_COM_READY_SLEEP sub-state of
                 a channel whose ComMNmVariant is FULL.                       \n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in vidManageFULLSM().
    \param[in]  ku8Channel The Channel for which the sub-states will be managed.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  kbLimToNoCom Indication whether a ComMNoCom limitation is active
                or not.                                                       \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbActiveUR Indication whether or not there is an active user
                request.                                                      \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoFullComRSFULL(
                                        const NetworkHandleType ku8Channel
                                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                        ,
                                        const boolean kbLimToNoCom,
                                        const boolean kbActiveUR
                                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                                        );


/******************************************************************************/
/*! \Description Function to handle the COMM_NO_COM_REQUEST_PENDING sub-state of
                 a channel whose ComMNmVariant is FULL.                       \n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in vidManageFULLSM().
    \param[in]  ku8Channel The Channel for which the sub-states will be managed.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  kbLimToNoCom Indication whether a ComMNoCom limitation is active
                or not.                                                       \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbNoWakeUp Indication whether a ComMNoWakeup limitation is
                active or not.                                                \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbActiveUR Indication whether or not there is an active user
                request.                                                      \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoNoComRPFULL(
                                        const NetworkHandleType ku8Channel,
                                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                        const boolean kbLimToNoCom,
                                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                                        const boolean kbActiveUR
                                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                        , const boolean kbNoWakeUp
                                        #endif /* ComM_bWAKEUP_INH_ENABLE */
                                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                                        );


/******************************************************************************/
/*! \Description Function to handle the COMM_SIELNT_COM sub-state of a channel
                 whose ComMNmVariant is FULL.                                 \n
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in vidManageFULLSM().
    \param[in]  ku8Channel The Channel for which the sub-states will be managed.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  kbLimToNoCom Indication whether a ComMNoCom limitation is active
                or not.                                                       \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbNoWakeUp Indication whether a ComMNoWakeup limitation is
                active or not.                                                \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbActiveUR Indication whether or not there is an active user
                request.                                                      \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoSilentComFULL(
                                    const NetworkHandleType ku8Channel,
                                    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                    const boolean kbLimToNoCom,
                                    #endif /* ComM_bMODE_LIMIT_ENABLE */
                                    const boolean kbActiveUR
                                    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                    , const boolean kbNoWakeUp
                                    #endif /* ComM_bWAKEUP_INH_ENABLE */
                                    #endif /* ComM_bMODE_LIMIT_ENABLE */
                                    );
#endif /* ComM_bANY_FULL_CHANNEL */

#if ((ComM_bANY_LIGHT_CHANNEL == TRUE) || (ComM_bANY_NI_NONE == TRUE))
/******************************************************************************/
/*! \Description Function to handle the COMM_NO_COM_REQUEST_PENDING sub-state of
                 a channel whose ComMNmVariant is either LIGHT or NONE and its
                 bus type is not INTERNAL.
    \param[in]  ku8Channel The Channel for which the sub-state will be managed.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  kbLimToNoCom Indication whether a ComMNoCom limitation is active
                or not.                                                       \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbNoWakeUp Indication whether a ComMNoWakeup limitation is
                active or not.                                                \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbActiveUR Indication whether or not there is an active user
                request.                                                      \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoReqPLightNINone(
                             const NetworkHandleType ku8Channel,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             const boolean kbLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             const boolean kbActiveUR
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , const boolean kbNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             );
#endif /* ComM_bANY_LIGHT_CHANNEL || ComM_bANY_NI_NONE */


#if ((ComM_bANY_LIGHT_CHANNEL == TRUE) || (ComM_bANY_NONE_CHANNEL == TRUE))
/******************************************************************************/
/*! \Description Function to handle the COMM_FULL_COM_NETWORK_REQUESTED
                 sub-state of a channel whose ComMNmVariant is either LIGHT or
                 NONE.
    \param[in]  ku8Channel The Channel for which the sub-state will be managed.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  kbLimToNoCom Indication whether a ComMNoCom limitation is active
                or not.                                                       \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbActiveUR Indication whether or not there is an active user
                request.                                                      \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in,out]  kpu32Cycles Pointer to the channel's main function
                    timer-counter.                                            \n
                    \Unit Pointer to uint32
    \param[in]  ku32MinFULLDur Minimum Full Communication main function counts.
                \n
                \Unit uint32
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoNETRQedLightNone(
                        const NetworkHandleType ku8Channel,
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        const boolean kbLimToNoCom,
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        const boolean kbActiveUR,
                        CONSTP2VAR(uint32,AUTOMATIC,COMM_APPL_DATA) kpu32Cycles,
                        const uint32 ku32MinFULLDur);
#endif /* ComM_bANY_LIGHT_CHANNEL || ComM_bANY_NONE_CHANNEL */

#if ((ComM_bANY_FULL_CHANNEL == TRUE) || (ComM_bANY_LIGHT_CHANNEL == TRUE) \
  || (ComM_bANY_NI_NONE == TRUE) \
  || ((ComM_bANY_NONE_CHANNEL == TRUE) && (ComM_bMODE_LIMIT_ENABLE == TRUE)))
/******************************************************************************/
/*! \Description Function to handle the COMM_NO_COM_NO_PENDING_REQUEST
                 sub-state of a channel whose ComMNmVariant is either FULL,
                 LIGHT or NONE.
    \param[in]  ku8Channel The Channel for which the sub-state will be managed.
                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  kbLimToNoCom Indication whether a ComMNoCom limitation is active
                or not.                                                       \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbNoWakeUp Indication whether a ComMNoWakeup limitation is
                active or not.                                                \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
    \param[in]  kbActiveUR Indication whether or not there is an active user
                request.                                                      \n
                \Range TRUE,FALSE                                             \n
                \Unit boolean
*******************************************************************************/
static FUNC(void, COMM_CODE) vidDoNoPFULLLightNone(
                             const NetworkHandleType ku8Channel,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             const boolean kbLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             const boolean kbActiveUR
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , const boolean kbNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             );
#endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_LIGHT_CHANNEL
       || ComM_bANY_NONE_CHANNEL */

#if (ComM_bANY_FULL_CHANNEL == TRUE)
/******************************************************************************/
/*! \Description Function to decrease the complexity of ComM_vidManageFULLSM()
                 by handling the sub-states created to repeat the call to
                 Nm_NetworkRequest().
                 It must be noted that it is better to make this function inline
                 since it is only referenced one time in ComM_vidManageFULLSM().
    \param[in]  ku8Channel The Channel for which Nm_NetworkRequest shall be
                           requested again.                                   \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
*******************************************************************************/
static void vidDoFULLNRStates(const NetworkHandleType ku8Channel);
#endif /* ComM_bANY_FULL_CHANNEL */


#if (ComM_bPNC_SUPPORT == TRUE)
/******************************************************************************/
/*! \Description Function to evaluate if there is a user request for the PNC \n
                 or not.           \n
    \param[in]  ku8PncIdInd The PNC_ID index.                                \n
                \Range 0..(ComM_u8NO_OF_PNCS-1)                          \n
                \Unit PNCHandleType
*******************************************************************************/
static FUNC(boolean, COMM_CODE) bEvalPncUserRequest(
                                               const PNCHandleType ku8PncIdInd);

/******************************************************************************/
/*! \Description Function to evaluate if the PNC can be in PNC_REQUESTED or not.
    \param[in]  ku8PncIdInd The PNC_ID index.                                \n
    \param[in]  kbDecFlag boolean flag for the decision of the exit condition.\n
                \Range 0..(ComM_u8NO_OF_PNCS-1)                          \n
                \Unit PNCHandleType
*******************************************************************************/
static FUNC(boolean, COMM_CODE) bCanPncNRRS(const PNCHandleType ku8PncIdInd);

/******************************************************************************/
/*! \Description Function to handle PNC state for user requests.
    \param[in]  ku8PncIdInd The PNC_ID index for which the state is handled.  \n
                \Range 0..(ComM_u8NO_OF_PNCS-1)                          \n
                \Unit PNCHandleType                                           \n
*******************************************************************************/
static FUNC(void, COMM_CODE) vidHandlePncState (
                                               const PNCHandleType ku8PncIdInd);

/******************************************************************************/
/*! \Description Function to handle PNC state for EIRA.
    \param[in] ku8Channel Channel ID calling this function.\n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in] kbEvalPS boolean to handle the timer of the PNC or not.        \n
                \Unit boolean
    \param[in]  ku8PncIdInd The PNC_ID index for which the state is handled.  \n
                \Range 0..(ComM_u8NO_OF_PNCS-1)                          \n
                \Unit PNCHandleType
*******************************************************************************/
static void vidEiraHandle(const NetworkHandleType ku8Channel,
                          const boolean kbEvalPS,
                          const PNCHandleType ku8PncIdInd);

/******************************************************************************/
/*! \Description Function to evaluate if the PNC prepare sleep timer can be be\n
                 evaluated by this channel or not or not.
    \param[in]  ku8PncIdInd The PNC_ID index.                                \n
                \Range 0..(ComM_u8NO_OF_PNCS-1)                          \n
                \Unit PNCHandleType
    \param[in]  ku8Channel The CHANNEL_ID index.                            \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[out]  boolean with the ability to evaluate the timer or not.     \n
                \Range TRUE, FALSE                          \n
                \Unit boolean.
*******************************************************************************/
static FUNC(boolean, COMM_CODE) bIsCountPncTimer(
                                            const PNCHandleType ku8PncIdInd,
                                            const NetworkHandleType ku8Channel);

#if (ComM_bPNC_GW_ENABLED == TRUE)
/******************************************************************************/
/*! \Description Function to handle PNC_GW functionality.    \n
    \param[in] ku8Channel Channel ID calling this function.\n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[in]  kbActGWCh boolean whether the channel is GW_ACTIVE or not.    \n
                \Range TRUE, FALSE                          \n
                \Unit boolean.
    \param[in]  ku8PncIdInd The PNC_ID index.                                \n
                \Range 0..(ComM_u8NO_OF_PNCS-1)                          \n
                \Unit PNCHandleType
*******************************************************************************/
static void vidEraGwHandle(
                            const NetworkHandleType ku8Channel,
                            const boolean kbActGWCh,
                            const PNCHandleType ku8PncIdInd
                            #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                            , const boolean kbLimToNoCom
                            #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                            , const boolean kbNoWakeUp
                            #endif /* ComM_bWAKEUP_INH_ENABLE */
                            #endif /* ComM_bMODE_LIMIT_ENABLE */
                            );

/******************************************************************************/
/*! \Description Function to evaluate if the GW PNC can be in PNC_REQUESTED or
                 not.
    \param[in]  ku8PncIdInd The PNC_ID index.                                \n
    \param[in]  kbDecFlag boolean flag for the decision of the exit condition.\n
                \Range 0..(ComM_u8NO_OF_PNCS-1)                          \n
                \Unit PNCHandleType
*******************************************************************************/
static FUNC(boolean, COMM_CODE) bCanPncGwNR(const PNCHandleType ku8PncIdInd);

/******************************************************************************/
/*! \Description Function to evaluate if there's any GW PNC mapped to this
                 channel requested or not.
    \param[in]  ku8Channel The Channel ID.                                \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
*******************************************************************************/
static FUNC(boolean, COMM_CODE) bIsGwChReq(const NetworkHandleType ku8Channel);

#endif /* ComM_bPNC_GW_ENABLED */
#endif /* ComM_bPNC_SUPPORT == TRUE */


/******************************************************************************/
/*                                  Code                                      */

/*! \Trace_To ComM-CDD-0091(0) */
#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
static FUNC(void, COMM_CODE) vidIncrInhCounter(void)
{
    /* !Deviation: Violates Misra Rule 54 "Null Statements do not occur on a
       line by itself, but this is not a mull statement, the function prototype
       was stubbed by a #define because critical sections may be implemented
       by compiler keywords and not necessarily functions. */
    /* PRQA S 3141 ++ */
    SchM_Enter_ComM_CounterSec();
    /* PRQA S 3141 -- */
    if (ComM_u16InhibitCounter < (uint16)u16INH_COUNTER_MAX)
    {
        ComM_u16InhibitCounter++;
    }
    /* PRQA S 3141 ++ */
    SchM_Exit_ComM_CounterSec();
    /* PRQA S 3141 -- */
}
#endif /* ComM_bMODE_LIMIT_ENABLE */

/******************************************************************************/

#if ((ComM_bANY_FULL_CHANNEL == TRUE)||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
static FUNC(void, COMM_CODE) vidGoToFCom(const NetworkHandleType ku8Channel)
{
    /*! Refer to ComM_Nm_NetworkStartIndication() for more Information about
        this function. */
    Std_ReturnType u8Return;
    boolean bInitTransition = TRUE;
    if (  ((ComM_au8StateMachines[ku8Channel]
                               == COMM_NO_COM_NO_PENDING_REQUEST) ||
          (ComM_au8StateMachines[ku8Channel] == COMM_NO_COM_REQUEST_PENDING))
        &&(ComM_abCommunicationAllowed[ku8Channel] == TRUE))
    {
        ComM_au8StateMachines[ku8Channel] = u8TRANS_NO_TO_FULL;
    }
    else if (ComM_au8StateMachines[ku8Channel] == COMM_SILENT_COM)
    {
        ComM_au8StateMachines[ku8Channel] = u8TRANS_SILENT_TO_FULL;
    }
    else
    {
        bInitTransition = FALSE;
        ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_REQUEST_PENDING;
    }
    ComM_au8WakeUpSleepStatus[ku8Channel] = u8PASSIVE_WAKEUP;
    if (bInitTransition == TRUE)
    {
        u8Return = ComM_pfu8RCOM_MODE(ku8Channel, COMM_FULL_COMMUNICATION);
        if (u8Return != E_OK)
        {
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8NM_NETWORK_START_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            #endif /* ComM_bDEV_ERROR_DETECT */
            if (ComM_au8StateMachines[ku8Channel] == u8TRANS_NO_TO_FULL)
            {
                ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_REQUEST_PENDING;
            }
            else
            {
                ComM_au8StateMachines[ku8Channel] = COMM_SILENT_COM;
            }
        }
    }
}

/******************************************************************************/

static FUNC(void, COMM_CODE) vidDoBusMITransToFull(
                                const NetworkHandleType ku8Channel)
{
    Std_ReturnType udtTReturn;

    /*! if wake-up reason is u8NONE */
    if (ComM_au8WakeUpSleepStatus[ku8Channel] == u8NONE)
    {
        /*! Switch to COMM_FULL_COM_NETWORK_REQUESTED */
        ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
        /*! Do Notifications */
        vidDoNotify(ku8Channel,COMM_FULL_COMMUNICATION);
    }

    /*! else if wake-up reason is u8PASSIVE_WAKEUP call
        Nm_PassiveStartUp() */
    else if (ComM_au8WakeUpSleepStatus[ku8Channel] == u8PASSIVE_WAKEUP)
    {
        /*! if DET is enabled report COMM_E_ERROR_IN_PROV_SERVICE if
            service returned with an error */
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        udtTReturn =
        #else
        (void)
        #endif /* ComM_bDEV_ERROR_DETECT */
        Nm_PassiveStartUp(ku8Channel);
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        if (udtTReturn == E_NOT_OK)
        {
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8BUS_SM_MODE_INDIC_ID, COMM_E_ERROR_IN_PROV_SERVICE);
        }
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    /*! else if wake-up reason is u8ACTIVE_WAKEUP call
                        Nm_NetworkRequest() */
    else if (ComM_au8WakeUpSleepStatus[ku8Channel] == u8ACTIVE_WAKEUP)
    {
        udtTReturn = Nm_NetworkRequest(ku8Channel);
        if (udtTReturn == E_NOT_OK)
        {
            /*! if service returned with an error, move to u8TRANS_NO_TO_FULL_NR
                or u8TRANS_SIL_TO_FULL_NR, and if DET is enabled report
                COMM_E_ERROR_IN_PROV_SERVICE. */
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8BUS_SM_MODE_INDIC_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            #endif /* ComM_bDEV_ERROR_DETECT */
            if (ComM_au8StateMachines[ku8Channel] == u8TRANS_NO_TO_FULL)
            {
                ComM_au8StateMachines[ku8Channel] = u8TRANS_NO_TO_FULL_NR;
            }
            else
            {
                ComM_au8StateMachines[ku8Channel] = u8TRANS_SIL_TO_FULL_NR;
            }
        }
    }

    else /*! else either wake-up reason is u8ENTER_READY_SLEEP or
             u8ENTER_NO_COM, the latter cannot happen in with the
             received state (namely COMM_FULL_COMMUNICATION)
             indication having assured there is no conflict in
             current and indicated communication modes, so else it
             must be u8ENTER_READY_SLEEP */
    {
        /*! Switch to COMM_FULL_COM_READY_SLEEP */
        ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_READY_SLEEP;
        /*! Do Notifications */
        vidDoNotify(ku8Channel, COMM_FULL_COMMUNICATION);
    }
}
#endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */

/******************************************************************************/

static FUNC(ComM_ModeType, COMM_CODE) u8GetUserComMode (
        const ComM_UserHandleType ku8User)
{
    uint16_least   u16Idx;
    ComM_StateType u8TempState;
    boolean        bBreak = FALSE;
    boolean        bSilentDetected = FALSE;
    ComM_ModeType  u8ReturnedComMode = COMM_FULL_COMMUNICATION;
    /*! Loop on each channel mapped to the user */
    for (u16Idx=0;(u16Idx<(u16USR_CH_REF_SIZE(ku8User)))
                          && (bBreak==FALSE); u16Idx++)
    {
        /*! if COMM_NO_COMMUNICATION is detected */
        u8TempState =
                ComM_au8StateMachines[pu8USR_CH_REF_ARRAY(ku8User)[u16Idx]];
        if (  (u8TempState == COMM_NO_COM_NO_PENDING_REQUEST)
            ||(u8TempState == COMM_NO_COM_REQUEST_PENDING)
            ||(u8TempState == u8TRANS_NO_TO_FULL))
        {
            u8ReturnedComMode = COMM_NO_COMMUNICATION;
            /*! BREAK LOOP by setting the Break boolean to TRUE */
            bBreak = TRUE;
        }
        /*! else if COMM_SILENT_COMMUNICATION detected, set the SilentDetected
            flag, and continue the Loop */
        else if (  (u8TempState == COMM_SILENT_COM)
                 ||(u8TempState == u8TRANS_SILENT_TO_FULL)
                 ||(u8TempState == u8TRANS_SILENT_TO_NO))
        {
            bSilentDetected = TRUE;
        }
        else
        {
            /*! Else Continue the Loop */
        }
    }
    /*! If Break boolean is False, and SilentDetected is also False; the return
        value will be left as initialised; COMM_FULL_COMMUNICATION\n
        If Break boolean is False, and SilentDetected is TRUE; set the
        return value to COMM_SILENT_COMMUNICATION\n
        Else of If Break boolean is TRUE; set the return value to
        COMM_NO_COMMUNICATION  */

    if ((bBreak == FALSE) && (bSilentDetected == TRUE))
    {
        u8ReturnedComMode = COMM_SILENT_COMMUNICATION;
    }
    return u8ReturnedComMode;
}

/******************************************************************************/

static FUNC(ComM_ModeType, COMM_CODE) u8GetChannelFutComMode(
        const NetworkHandleType ku8Channel)
{
    ComM_ModeType u8Return;
    switch (ComM_au8StateMachines[ku8Channel])
    {
        case COMM_NO_COM_NO_PENDING_REQUEST:
        case COMM_NO_COM_REQUEST_PENDING:
        case u8TRANS_FULL_TO_NO:
        case u8TRANS_SILENT_TO_NO:
            u8Return = COMM_NO_COMMUNICATION;
            break;
        case COMM_SILENT_COM:
        case u8TRANS_FULL_TO_SILENT:
            u8Return = COMM_SILENT_COMMUNICATION;
            break;
        default:
            u8Return = COMM_FULL_COMMUNICATION;
            break;
    }
    return u8Return;
}

/* !Deviation: [4700] "Metric value out of threshold range: vidDoNotify() :
    STSUB (No. of Function Calls) = 11."
    This is justifiable since there is three functions for the Dcm each for a
    certain communication mode, and for the user there is a function call that
    returns a structure from which a pointer to function is retrieved and that
    function is called with its argument a one of three symbols whose types are
    not known.
*/
/* PRQA S 4700 ++*/

/******************************************************************************/
static FUNC(void, COMM_CODE) vidDoNotify(const NetworkHandleType ku8Channel,
                                         const ComM_ModeType ku8ComMode)
{
    uint8_least   u8Idx;
    ComM_ModeType u8TComMode;
    /*! Notify BswM */
    BswM_ComM_CurrentMode(ku8Channel, ku8ComMode);

    #if (ComM_bCOMM_DCM_ENABLED == TRUE)
    /*! Check Indicated State and Notify DCM*/
    if (ku8ComMode == COMM_FULL_COMMUNICATION)
    {
        Dcm_ComM_FullComModeEntered(ku8Channel);
    }
    else if (ku8ComMode == COMM_SILENT_COMMUNICATION)
    {
        Dcm_ComM_SilentComModeEntered(ku8Channel);
    }
    else
    {
        Dcm_ComM_NoComModeEntered(ku8Channel);
    }
    #endif /* ComM_bCOMM_DCM_ENABLED */

    /*! Loop on channel's users */
    for (u8Idx = 0; u8Idx < u8CH_USR_REF_SIZE(ku8Channel); u8Idx++)
    {
        /*! Get minimum communication mode for User and notify with it.*/
        u8TComMode = u8GetUserComMode(pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]);

        if (u8TComMode == COMM_FULL_COMMUNICATION)
        {
            #if (ComM_bRTE_USED == STD_ON)
            (void)akpfu8MSI_ARRAY[pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]]
                                    (RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION);
            #elif (ComM_bRTE_USED == STD_OFF)                       
            (void)akpfu8MSI_ARRAY[pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]]
                                    (USER_MODE_ComMMode_COMM_FULL_COMMUNICATION);
            #endif /* ComM_bRTE_USED */
        }
        else if (u8TComMode == COMM_SILENT_COMMUNICATION)
        {
            #if (ComM_bRTE_USED == STD_ON)
            (void)akpfu8MSI_ARRAY[pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]]
                                  (RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION);
            #elif (ComM_bRTE_USED == STD_OFF)                     
            (void)akpfu8MSI_ARRAY[pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]]
                                  (USER_MODE_ComMMode_COMM_SILENT_COMMUNICATION);
            #endif /* ComM_bRTE_USED */                     
        }
        else
        {
            #if (ComM_bRTE_USED == STD_ON)
            (void)akpfu8MSI_ARRAY[pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]]
                                      (RTE_MODE_ComMMode_COMM_NO_COMMUNICATION);
            #elif (ComM_bRTE_USED == STD_OFF)                         
            (void)akpfu8MSI_ARRAY[pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]]
                                      (USER_MODE_ComMMode_COMM_NO_COMMUNICATION);
            #endif /* ComM_bRTE_USED */                          
        }
    }
}
/* PRQA S 4700 --*/

/******************************************************************************/

#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
static FUNC(void, COMM_CODE) vidClearFaultyRequests(
                             const NetworkHandleType ku8Channel)
{
    uint8_least               u8Idx;
    uint16_least              u16Idx2;
    boolean             bBreak;
    NetworkHandleType   u8TChannel;
    ComM_UserHandleType u8TUser;
    for (u8Idx = 0; u8Idx < u8CH_USR_REF_SIZE(ku8Channel); u8Idx++)
    {
        bBreak = FALSE;
        u8TUser = pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx];
        for (u16Idx2 = 0;
                ((u16Idx2 < u16USR_CH_REF_SIZE(u8TUser)) && (bBreak == FALSE));
                u16Idx2++)
        {
            u8TChannel = pu8USR_CH_REF_ARRAY(u8TUser)[u16Idx2];
            if (  (ComM_au8StateMachines[u8TChannel]
                                       != COMM_NO_COM_NO_PENDING_REQUEST)
                ||(ComM_abeLimitToNoComStatus[u8TChannel] == FALSE))
            {
                bBreak = TRUE;
            }
        }
        if (bBreak == FALSE)
        {
            ComM_abUserRequestStatus[u8TUser] = FALSE;
        }
    }
}
#endif /* ComM_bMODE_LIMIT_ENABLE */

/******************************************************************************/

static FUNC(Std_ReturnType, COMM_CODE) u8HandleFComReq(
                                       const ComM_UserHandleType ku8User)
{
    Std_ReturnType    u8Return = E_OK;
    uint16_least      u16Idx;
    NetworkHandleType u8TChannel;
    #if ((ComM_bANY_FULL_CHANNEL == TRUE)||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
    uint8             u8TempWakeStatus;
    #endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    boolean           bInhibited;
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
    boolean           bStatusChanged;
    /*! if the User's previous request was COMM_NO_COMMUNICATION, set
        bStatusChanged to TRUE to be used in updating channel's value
        in ComM_abChannelReqsUpdated to TRUE later. */
    bStatusChanged = !(ComM_abUserRequestStatus[ku8User]);
    #endif /* ComM_bANY_FCOM_SRI_ENABLE */
    /*! Set user request status to TRUE */
    ComM_abUserRequestStatus[ku8User] = TRUE;
    /*! For each channel mapped to the user do the following: */
    for (u16Idx=0; u16Idx<u16USR_CH_REF_SIZE(ku8User); u16Idx++)
    {
        u8TChannel = pu8USR_CH_REF_ARRAY(ku8User)[u16Idx];
        /*! evaluate inhibition status according to type of inhibition and
            current mode */
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        if ((ComM_au8StateMachines[u8TChannel] ==
                     COMM_FULL_COM_NETWORK_REQUESTED)
          ||(ComM_au8StateMachines[u8TChannel] ==
                     COMM_FULL_COM_READY_SLEEP))
        {
        #endif /* ComM_bWAKEUP_INH_ENABLE */
            bInhibited = ((bCHK_LIMNOCOM_GC == 1) &&
                             (ComM_abeLimitToNoComStatus[u8TChannel] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        }
        else
        {
            bInhibited = (  ((bCHK_LIMNOCOM_GC == 1) &&
                             (ComM_abeLimitToNoComStatus[u8TChannel] != FALSE))
                          ||((bCHK_NOWAKEUP_GC == 1) &&
                             (ComM_abeWakeUpInibitStatus[u8TChannel] != FALSE))
                         );
        }
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        /*! if channel is not inhibited: */
        if (bInhibited == FALSE)
        {
            #endif /* ComM_bMODE_LIMIT_ENABLE */
            #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
            /*! if the User's previous request was COMM_NO_COMMUNICATION, set
                channel's value in ComM_abChannelReqsUpdated to TRUE. */
            ComM_abeChannelReqsUpdated[u8TChannel] = bStatusChanged;
            #endif /* ComM_bANY_FCOM_SRI_ENABLE */
            /*! Switch on channel's applicable sub-states */
            switch (ComM_au8StateMachines[u8TChannel])
            {
            /*! in case of COMM_FULL_COM_NETWORK_REQUESTED or
                COMM_FULL_COM_READY_SLEEP */
            case COMM_FULL_COM_NETWORK_REQUESTED:
            case COMM_FULL_COM_READY_SLEEP:
                /*! Set ACTIVE_WAKEUP flag so that Nm_NetworkRequest() May be
                    Called if channel's ComMNmVariant was FULL */
                ComM_au8WakeUpSleepStatus[u8TChannel] = u8ACTIVE_WAKEUP;
                /*! Switch to COMM_FULL_COM_NETWORK_REQUESTED, in case it was
                    already COMM_FULL_COM_NETWORK_REQUESTED then no harm done */
                ComM_au8StateMachines[u8TChannel] =
                        COMM_FULL_COM_NETWORK_REQUESTED;
                break;
            /*! in case of COMM_NO_COM_NO_PENDING_REQUEST switch to
                COMM_NO_COM_REQUEST_PENDING */
            case COMM_NO_COM_NO_PENDING_REQUEST:
                ComM_au8StateMachines[u8TChannel] = COMM_NO_COM_REQUEST_PENDING;
                break;
            /*! \note In case COMM_SILENT_COM, the following should be noted:\n
                      For a channel to be present in COMM_SILENT_COM this means
                      that its ComMNmVariant is either FULL or PASSIVE, since
                      LIGHT and NONE channels cannot go to that state, and since
                      the channel is mapped to a user and a PASSIVE channel
                      cannot be mapped to a user then this channel must be FULL,
                      so delaying the transition to COMM_FULL_COMMUNICATION is
                      meaningless since the only reason it's delayed anywhere is
                      because channels' ComMNmVariant configuration is not known
                      throughout the module and only in its the channel's Main
                      function.\n */
            /*! So we handle the transition to COMM_FULL_COMMUNICATION by doing
                the following: */
            #if (  (ComM_bANY_FULL_CHANNEL == TRUE)\
                 ||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
            case COMM_SILENT_COM:
                /*! Switch to transient state u8TRANS_SILENT_TO_FULL */
                ComM_au8StateMachines[u8TChannel] = u8TRANS_SILENT_TO_FULL;
                /*! set channel's value in ComM_au8WakeUpSleepStatus to
                    u8ACTIVE_WAKEUP so that ComM_BusSm_ModeIndication() can call
                    Nm_NetworkRequest() */
                u8TempWakeStatus = ComM_au8WakeUpSleepStatus[u8TChannel];
                ComM_au8WakeUpSleepStatus[u8TChannel] = u8ACTIVE_WAKEUP;
                /*! Request COMM_FULL_COMMUNICATION from the BusSM */
                u8Return = ComM_pfu8RCOM_MODE(u8TChannel, COMM_FULL_COMMUNICATION);

                if (u8Return != E_OK)
                {
                    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                                    ComM_u8REQUEST_COM_MODE_ID,
                                    COMM_E_ERROR_IN_PROV_SERVICE);
                    #endif /* ComM_bDEV_ERROR_DETECT */
                    ComM_au8StateMachines[u8TChannel] = COMM_SILENT_COM;
                    ComM_au8WakeUpSleepStatus[u8TChannel] = u8TempWakeStatus;
                }
                break;
            #endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */
            default:
                /*! The rest of the states are transient state so if they do not
                    ultimately match the requested ComMode it is safer to leave
                    it to the Main function to finish the current transition
                    before making. */
                break;
            }
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        }
        /*! if Channel \e was inhibited then set the value to be returned to
            COMM_E_MODE_LIMITATION so that ComM_RequestComMode() can
            consequently return it. */
        else
        {
            u8Return = COMM_E_MODE_LIMITATION;
        }
        #endif /* ComM_bMODE_LIMIT_ENABLE */
    }
    return u8Return;
}

/******************************************************************************/

#if (ComM_bANY_FULL_CHANNEL == TRUE)
static FUNC(void, COMM_CODE) vidDoFullComNWFULL(
                                        const NetworkHandleType ku8Channel,
                                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                        const boolean kbLimToNoCom,
                                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                                        const boolean kbActiveUR)
{
    Std_ReturnType udtTReturn;
    if (  (  (kbActiveUR == FALSE)
           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
           ||(kbLimToNoCom != FALSE)
           #endif /* ComM_bMODE_LIMIT_ENABLE */
          )
        #if (ComM_bCOMM_DCM_ENABLED == TRUE)
        &&(ComM_abDCMActiveDiagnostic[ku8Channel] == FALSE)
        #endif /* ComM_bCOMM_DCM_ENABLED */
       )
    {
        ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_READY_SLEEP;
        ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        udtTReturn =
        #else
        (void)
        #endif /* ComM_bDEV_ERROR_DETECT */
        Nm_NetworkRelease(ku8Channel);
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        if (udtTReturn == E_NOT_OK)
        {
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
        }
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (ComM_au8WakeUpSleepStatus[ku8Channel] == u8ACTIVE_WAKEUP)
    {
        udtTReturn = Nm_NetworkRequest(ku8Channel);
        if (udtTReturn == E_NOT_OK)
        {
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            #endif /* ComM_bDEV_ERROR_DETECT */
        }
        else
        {
            ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
        }
    }
    else
    {
        /*! Do Nothing */
    }
}

/******************************************************************************/

static FUNC(void, COMM_CODE) vidDoFullComRSFULL(
                                        const NetworkHandleType ku8Channel
                                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                        ,
                                        const boolean kbLimToNoCom,
                                        const boolean kbActiveUR
                                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                                        )
{
    /*! this test is only valid if there is a lifted mode limitation,
        otherwise, ComM_RequestComMode should make the transition, also,
        DCMActiveDiagnostic always makes the transition so checking it is
        not necessary  */
    #if ((ComM_bDEV_ERROR_DETECT == STD_ON)||(ComM_bMODE_LIMIT_ENABLE == TRUE))
    Std_ReturnType udtTReturn;
    #endif /* ComM_bDEV_ERROR_DETECT || ComM_bMODE_LIMIT_ENABLE */
    #if(ComM_bMODE_LIMIT_ENABLE == TRUE)
    if ((kbActiveUR != FALSE)&&(kbLimToNoCom == FALSE))
    {
        ComM_au8WakeUpSleepStatus[ku8Channel] = u8ACTIVE_WAKEUP;
        ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
        udtTReturn = Nm_NetworkRequest(ku8Channel);
        if (udtTReturn == E_NOT_OK)
        {
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            #endif /* ComM_bDEV_ERROR_DETECT */
        }
        else
        {
            ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
        }
    }
    else if (ComM_au8WakeUpSleepStatus[ku8Channel] == u8ENTER_READY_SLEEP)
    #else
    if (ComM_au8WakeUpSleepStatus[ku8Channel] == u8ENTER_READY_SLEEP)
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    {
        ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        udtTReturn =
        #else
        (void)
        #endif /* ComM_bDEV_ERROR_DETECT */
        Nm_NetworkRelease(ku8Channel);
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        if (udtTReturn == E_NOT_OK)
        {
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
        }
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    #if(ComM_bMODE_LIMIT_ENABLE == TRUE)
    else
    {
        /*! Do Nothing */
    }
    #endif /* ComM_bMODE_LIMIT_ENABLE */
}

/******************************************************************************/

static FUNC(void, COMM_CODE) vidDoNoComRPFULL(
                                        const NetworkHandleType ku8Channel,
                                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                        const boolean kbLimToNoCom,
                                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                                        const boolean kbActiveUR
                                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                        , const boolean kbNoWakeUp
                                        #endif /* ComM_bWAKEUP_INH_ENABLE */
                                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                                        )
{
    Std_ReturnType u8Return;
    if (  (  (kbActiveUR != FALSE)
           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
           &&(kbLimToNoCom == FALSE)
           #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
           &&(kbNoWakeUp == FALSE)
           #endif /* ComM_bWAKEUP_INH_ENABLE */
           #endif /* ComM_bMODE_LIMIT_ENABLE */
          )
        #if (ComM_bCOMM_DCM_ENABLED == TRUE)
        ||(ComM_abDCMActiveDiagnostic[ku8Channel] != FALSE)
        #endif /* ComM_bCOMM_DCM_ENABLED */
        ||(ComM_au8WakeUpSleepStatus[ku8Channel] == u8PASSIVE_WAKEUP)
       )
    {
        if (ComM_au8WakeUpSleepStatus[ku8Channel] != u8PASSIVE_WAKEUP)
        {
            ComM_au8WakeUpSleepStatus[ku8Channel] = u8ACTIVE_WAKEUP;
        }
        if (ComM_abCommunicationAllowed[ku8Channel] != FALSE)
        {
            ComM_au8StateMachines[ku8Channel] = u8TRANS_NO_TO_FULL;
            u8Return = ComM_pfu8RCOM_MODE(ku8Channel, COMM_FULL_COMMUNICATION);
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                        ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_REQUEST_PENDING;
            }
        }
    }
    else
    {
        ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
        ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
        /*! if reason for transition is a Limit to No Communication; then we
            should check for faulty requests and clear them */
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        if((kbLimToNoCom != FALSE) && (kbActiveUR != FALSE))
        {
            vidClearFaultyRequests(ku8Channel);
        }
        #endif /* ComM_bMODE_LIMIT_ENABLE */
    }
}


/******************************************************************************/

static FUNC(void, COMM_CODE) vidDoSilentComFULL(
                                    const NetworkHandleType ku8Channel,
                                    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                    const boolean kbLimToNoCom,
                                    #endif /* ComM_bMODE_LIMIT_ENABLE */
                                    const boolean kbActiveUR
                                    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                    , const boolean kbNoWakeUp
                                    #endif /* ComM_bWAKEUP_INH_ENABLE */
                                    #endif /* ComM_bMODE_LIMIT_ENABLE */
                                    )
{
    Std_ReturnType u8Return;
    boolean bActiveReason =
            (  (kbActiveUR != FALSE)
             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
             &&(kbLimToNoCom == FALSE)
             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
             &&(kbNoWakeUp == FALSE)
             #endif /* ComM_bWAKEUP_INH_ENABLE */
             #endif /* ComM_bMODE_LIMIT_ENABLE */
            )
             #if (ComM_bCOMM_DCM_ENABLED == TRUE)
             ||(ComM_abDCMActiveDiagnostic[ku8Channel] != FALSE)
             #endif /* ComM_bCOMM_DCM_ENABLED */
            ;
    if (  bActiveReason
        ||(ComM_au8WakeUpSleepStatus[ku8Channel] == u8PASSIVE_WAKEUP)
        ||(ComM_au8WakeUpSleepStatus[ku8Channel] == u8ENTER_READY_SLEEP)
       )
    {
        /* !Deviation: [3344] bActiveReason is used directly without derivation
           from a logical expression because it previously initialized using
           derivation from a logical expression */
        /* PRQA S 3344 ++ */
        if (bActiveReason)
        /* PRQA S 3344 -- */
        {
            ComM_au8WakeUpSleepStatus[ku8Channel] = u8ACTIVE_WAKEUP;
        }
        ComM_au8StateMachines[ku8Channel] = u8TRANS_SILENT_TO_FULL;
        u8Return = ComM_pfu8RCOM_MODE(ku8Channel, COMM_FULL_COMMUNICATION);
        if (u8Return != E_OK)
        {
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                         ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            #endif /* ComM_bDEV_ERROR_DETECT */
            ComM_au8StateMachines[ku8Channel] = COMM_SILENT_COM;
        }
    }
}
#endif /* ComM_bANY_FULL_CHANNEL */

/******************************************************************************/

#if ((ComM_bANY_LIGHT_CHANNEL == TRUE) || (ComM_bANY_NONE_CHANNEL == TRUE))
static FUNC(void, COMM_CODE) vidDoNETRQedLightNone(
                        const NetworkHandleType ku8Channel,
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        const boolean kbLimToNoCom,
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        const boolean kbActiveUR,
                        CONSTP2VAR(uint32,AUTOMATIC,COMM_APPL_DATA) kpu32Cycles,
                        const uint32 ku32MinFULLDur)
{
    *kpu32Cycles = *kpu32Cycles + 1;
    if (  (  (kbActiveUR != FALSE)
           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
           &&(kbLimToNoCom == FALSE)
           #endif /* ComM_bMODE_LIMIT_ENABLE */
          )
        #if (ComM_bCOMM_DCM_ENABLED == TRUE)
        ||(ComM_abDCMActiveDiagnostic[ku8Channel] != FALSE)
        #endif /* ComM_bCOMM_DCM_ENABLED */
       )
    {
        /*! reset timer*/
        *kpu32Cycles = 0;
        ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
    }
    else if (  ((*kpu32Cycles) > ku32MinFULLDur)
             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
             ||(kbLimToNoCom != FALSE)
             #endif /* ComM_bMODE_LIMIT_ENABLE */
            )
    {
        ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_READY_SLEEP;
        *kpu32Cycles = 0;
    }
    else
    {
        /* Do Nothing */
    }
}
#endif /* ComM_bANY_LIGHT_CHANNEL || ComM_bANY_NONE_CHANNEL */

/******************************************************************************/

#if ((ComM_bANY_FULL_CHANNEL == TRUE) || (ComM_bANY_LIGHT_CHANNEL == TRUE) \
  || (ComM_bANY_NI_NONE == TRUE) \
  || ((ComM_bANY_NONE_CHANNEL == TRUE) && (ComM_bMODE_LIMIT_ENABLE == TRUE)))
static FUNC(void, COMM_CODE) vidDoNoPFULLLightNone(
                             const NetworkHandleType ku8Channel,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             const boolean kbLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             const boolean kbActiveUR
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , const boolean kbNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             )
{
    if (  (  (kbActiveUR != FALSE)
           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
           &&(kbLimToNoCom == FALSE)
           #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
           &&(kbNoWakeUp == FALSE)
           #endif /* ComM_bWAKEUP_INH_ENABLE */
           #endif /* ComM_bMODE_LIMIT_ENABLE */
          )
        #if (ComM_bCOMM_DCM_ENABLED == TRUE)
        ||(ComM_abDCMActiveDiagnostic[ku8Channel] != FALSE)
        #endif /* ComM_bCOMM_DCM_ENABLED */
       )
    {
        ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_REQUEST_PENDING;
    }
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    if ((ComM_au8WakeUpSleepStatus[ku8Channel] == u8ENTER_NO_COMM) &&
            (kbLimToNoCom != FALSE))
    {
        vidClearFaultyRequests(ku8Channel);
        #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
        ComM_abeChannelReqsUpdated[ku8Channel] = TRUE;
        #endif /* ComM_bANY_FCOM_SRI_ENABLE */
    }
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
}
#endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_LIGHT_CHANNEL || ComM_bANY_NI_NONE
        || (ComM_bANY_NONE_CHANNEL && ComM_bMODE_LIMIT_ENABLE) */
/******************************************************************************/

#if ((ComM_bANY_LIGHT_CHANNEL == TRUE) || (ComM_bANY_NI_NONE == TRUE))
static FUNC(void, COMM_CODE) vidDoReqPLightNINone(
                             const NetworkHandleType ku8Channel,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             const boolean kbLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             const boolean kbActiveUR
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , const boolean kbNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             )
{
    Std_ReturnType u8Return;
    uint8          u8TempWakeStatus;
    if (  (  (kbActiveUR != FALSE)
           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
           &&(kbLimToNoCom == FALSE)
           #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
           &&(kbNoWakeUp == FALSE)
           #endif /* ComM_bWAKEUP_INH_ENABLE */
           #endif /* ComM_bMODE_LIMIT_ENABLE */
          )
        #if (ComM_bCOMM_DCM_ENABLED == TRUE)
        ||(ComM_abDCMActiveDiagnostic[ku8Channel] != FALSE)
        #endif /* ComM_bCOMM_DCM_ENABLED */
        ||(ComM_au8WakeUpSleepStatus[ku8Channel] == u8PASSIVE_WAKEUP)
       )
    {
        if (ComM_abCommunicationAllowed[ku8Channel] != FALSE)
        {
            u8TempWakeStatus = ComM_au8WakeUpSleepStatus[ku8Channel];
            ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
            ComM_au8StateMachines[ku8Channel] = u8TRANS_NO_TO_FULL;
            u8Return = ComM_pfu8RCOM_MODE(ku8Channel, COMM_FULL_COMMUNICATION);
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                         ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                ComM_au8WakeUpSleepStatus[ku8Channel] = u8TempWakeStatus;
                ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_REQUEST_PENDING;
            }
        }
    }
    else
    {
        ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
        ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
        /*! if reason for transition is a Limit to No Communication; then we
            should check for faulty requests and clear them */
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        if(kbLimToNoCom != FALSE)
        {
            vidClearFaultyRequests(ku8Channel);
        }
        #endif /* ComM_bMODE_LIMIT_ENABLE */
    }
}
#endif /* ComM_bANY_LIGHT_CHANNEL || ComM_bANY_NI_NONE */


/******************************************************************************/
#if (ComM_bANY_FULL_CHANNEL == TRUE)
static void vidDoFULLNRStates(const NetworkHandleType ku8Channel)
{
    Std_ReturnType udtReturn;
    if (  (ComM_au8StateMachines[ku8Channel] == u8TRANS_NO_TO_FULL_NR)
        ||(ComM_au8StateMachines[ku8Channel] == u8TRANS_SIL_TO_FULL_NR))
    {
        udtReturn = Nm_NetworkRequest(ku8Channel);
        if (udtReturn == E_NOT_OK)
        {
            /*! if service returned with an error, move to u8TRANS_NO_TO_FULL_NR
                and if DET is enabled report COMM_E_ERROR_IN_PROV_SERVICE
                 */
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            #endif /* ComM_bDEV_ERROR_DETECT */
        }
        else
        {
            ComM_au8StateMachines[ku8Channel] =
                    ComM_au8StateMachines[ku8Channel] - 5;
        }
    }
}
#endif /* ComM_bANY_FULL_CHANNEL */


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#if (ComM_bANY_INTERNAL_CHANNEL == TRUE)
FUNC(Std_ReturnType, COMM_CODE) ComM_u8GetInternalBusMode(
                   NetworkHandleType u8Network,
                   P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) pu8ComMModePtr)
{
    if (  (ComM_au8StateMachines[u8Network] == COMM_FULL_COM_NETWORK_REQUESTED)
        ||(ComM_au8StateMachines[u8Network] == COMM_FULL_COM_READY_SLEEP))
    {
        *pu8ComMModePtr = COMM_FULL_COMMUNICATION;
    }
    else
    {
        *pu8ComMModePtr = COMM_NO_COMMUNICATION;
    }
    return E_OK;
}
#endif /* ComM_bANY_INTERNAL_CHANNEL */
/******************************************************************************/

FUNC(boolean, COMM_CODE) ComM_bEvalChUserRequest(
                                const NetworkHandleType ku8Channel)
{
    uint8_least   u8Idx;
    #if ((ComM_bPNC_SUPPORT == TRUE) && (ComM_bPNC_GW_ENABLED == TRUE))
    boolean bActiveRequest = ComM_abChGwPncReq[ku8Channel];
    #else /* ((ComM_bPNC_SUPPORT) && (ComM_bPNC_GW_ENABLED)) */
    boolean bActiveRequest = FALSE;
    #endif /* ((ComM_bPNC_SUPPORT) && (ComM_bPNC_GW_ENABLED)) */
    for (u8Idx = 0; ((u8Idx < u8CH_USR_REF_SIZE(ku8Channel)) &&
                     (bActiveRequest == FALSE)); u8Idx++)
    {
        bActiveRequest =
               ComM_abUserRequestStatus[pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]];
    }
    return bActiveRequest;
}

/******************************************************************************/

#if (ComM_bANY_PASSIVE_CHANNEL == TRUE)
FUNC(void, COMM_CODE) ComM_vidManagePASSIVESM(
                                const NetworkHandleType ku8Channel)
{
    Std_ReturnType u8Return;
    switch (ComM_au8StateMachines[ku8Channel])
    {
    case COMM_NO_COM_REQUEST_PENDING:
        if (ComM_abCommunicationAllowed[ku8Channel] != FALSE)
        {
            ComM_au8StateMachines[ku8Channel] = u8TRANS_NO_TO_FULL;
            u8Return = ComM_pfu8RCOM_MODE(ku8Channel, COMM_FULL_COMMUNICATION);
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                        ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_REQUEST_PENDING;
            }
        }
        break;
    case COMM_FULL_COM_NETWORK_REQUESTED:
        ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_READY_SLEEP;
        ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
        break;
    case COMM_FULL_COM_READY_SLEEP:
        ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
            break;
    case COMM_SILENT_COM:
        if (  (ComM_au8WakeUpSleepStatus[ku8Channel] == u8PASSIVE_WAKEUP)
            ||(ComM_au8WakeUpSleepStatus[ku8Channel] == u8ENTER_READY_SLEEP))
        {
            ComM_au8StateMachines[ku8Channel] = u8TRANS_SILENT_TO_FULL;
            u8Return = ComM_pfu8RCOM_MODE(ku8Channel, COMM_FULL_COMMUNICATION);
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                        ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                ComM_au8StateMachines[ku8Channel] = COMM_SILENT_COM;
            }
        }
        break;
    default:
        break;
    }
}
#endif /* ComM_bANY_PASSIVE_CHANNEL */


/******************************************************************************/
#if (ComM_bANY_FULL_CHANNEL == TRUE)
FUNC(void, COMM_CODE) ComM_vidManageFULLSM(const NetworkHandleType ku8Channel,
                                           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                           const boolean kbLimToNoCom,
                                           #endif /* ComM_bMODE_LIMIT_ENABLE */
                                           const boolean kbActiveUR
                                           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                           #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                           , const boolean kbNoWakeUp
                                           #endif /* ComM_bWAKEUP_INH_ENABLE */
                                           #endif /* ComM_bMODE_LIMIT_ENABLE */
                                           )
{
    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
    Std_ReturnType  udtTReturn;
    #endif /* ComM_bDEV_ERROR_DETECT */
    #if (ComM_bPNC_SUPPORT == TRUE)
    uint8_least u8Idx;
    #endif /* ComM_bPNC_SUPPORT */
    /*!Evaluate PNC user requests.*/
    #if (ComM_bPNC_SUPPORT == TRUE)
    if (ComM_bePncEnabled != FALSE)
    {
        for (u8Idx = 0 ; u8Idx < u8CH_PNC_REF_SIZE(ku8Channel) ; u8Idx++)
        {
            vidHandlePncState(u8CH_PNC_REF_ARRAY(ku8Channel)[u8Idx]);
        }
    }
    #endif /*ComM_bPNC_SUPPORT */
    switch (ComM_au8StateMachines[ku8Channel])
    {
    case COMM_NO_COM_NO_PENDING_REQUEST:
        if (ComM_au8WakeUpSleepStatus[ku8Channel] == u8ENTER_NO_COMM)
        {
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            udtTReturn =
            #else
            (void)
            #endif /* ComM_bDEV_ERROR_DETECT */
            Nm_NetworkRelease(ku8Channel);
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            if (udtTReturn == E_NOT_OK)
            {
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                         ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            }
            #endif /* ComM_bDEV_ERROR_DETECT */
        }
        vidDoNoPFULLLightNone(ku8Channel,
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              kbLimToNoCom,
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              kbActiveUR
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                              , kbNoWakeUp
                              #endif /* ComM_bWAKEUP_INH_ENABLE */
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              );
        break;
    case COMM_NO_COM_REQUEST_PENDING:
        vidDoNoComRPFULL(ku8Channel,
                         #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                         kbLimToNoCom,
                         #endif /* ComM_bMODE_LIMIT_ENABLE */
                         kbActiveUR
                         #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                         #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                         , kbNoWakeUp
                         #endif /* ComM_bWAKEUP_INH_ENABLE */
                         #endif /* ComM_bMODE_LIMIT_ENABLE */
                         );
        break;
    case COMM_SILENT_COM:
        vidDoSilentComFULL(ku8Channel,
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        kbLimToNoCom,
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        kbActiveUR
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                        , kbNoWakeUp
                        #endif /* ComM_bWAKEUP_INH_ENABLE */
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        );
        break;
    case COMM_FULL_COM_NETWORK_REQUESTED:
        vidDoFullComNWFULL(ku8Channel,
                           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                           kbLimToNoCom,
                           #endif /* ComM_bMODE_LIMIT_ENABLE */
                           kbActiveUR);
        break;
    case COMM_FULL_COM_READY_SLEEP:
        vidDoFullComRSFULL(ku8Channel
                           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                           ,
                           kbLimToNoCom,
                           kbActiveUR
                           #endif /* ComM_bMODE_LIMIT_ENABLE */
                           );
        break;
    default:
        vidDoFULLNRStates(ku8Channel);
        break;
    }
}
#endif /* ComM_bANY_FULL_CHANNEL */

/******************************************************************************/
#if (ComM_bANY_LIGHT_CHANNEL == TRUE)
FUNC(void, COMM_CODE) ComM_vidManageLIGHTSM(const NetworkHandleType ku8Channel,
                                       #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                       const boolean kbLimToNoCom,
                                       #endif /* ComM_bMODE_LIMIT_ENABLE */
                                       const boolean kbActiveUR,
                                       uint32* const kpu32Cycles,
                                       const uint32 ku32MinFULLDur,
                                       #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                       #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                       const boolean kbNoWakeUp,
                                       #endif /* ComM_bWAKEUP_INH_ENABLE */
                                       #endif /* ComM_bMODE_LIMIT_ENABLE */
                                       const uint32 ku32LightTOut)
{
    Std_ReturnType u8Return;
    switch (ComM_au8StateMachines[ku8Channel])
    {
    case COMM_NO_COM_NO_PENDING_REQUEST:
        vidDoNoPFULLLightNone(ku8Channel,
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              kbLimToNoCom,
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              kbActiveUR
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                              , kbNoWakeUp
                              #endif /* ComM_bWAKEUP_INH_ENABLE */
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              );
        break;
    case COMM_NO_COM_REQUEST_PENDING:
        vidDoReqPLightNINone(ku8Channel,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             kbLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             kbActiveUR
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , kbNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             );
        break;
    case COMM_FULL_COM_NETWORK_REQUESTED:
        vidDoNETRQedLightNone(ku8Channel,
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              kbLimToNoCom,
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              kbActiveUR,
                              kpu32Cycles,
                              ku32MinFULLDur);
        break;
    case COMM_FULL_COM_READY_SLEEP:
        /*! Start/Increment timer */
        *kpu32Cycles = *kpu32Cycles+1;
        if ((kbActiveUR != FALSE)
                #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                && (kbLimToNoCom == FALSE)
                #endif /* ComM_bMODE_LIMIT_ENABLE */
           )
        {
            ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
        }
        /*! check if timer has expired */
        else if ((*kpu32Cycles) > ku32LightTOut)
        {
            /*! expired; switch to COMM_NO_COMMUNICATION*/
            ComM_au8StateMachines[ku8Channel] = u8TRANS_FULL_TO_NO;
            (*kpu32Cycles) = 0;
            u8Return = ComM_pfu8RCOM_MODE(ku8Channel, COMM_NO_COMMUNICATION);
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                        ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                (*kpu32Cycles) = ku32LightTOut + 1;
                ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_READY_SLEEP;
            }
        }
        else
        {
            /* Do Nothing */
        }
        break;
    default:
        break;
    }
}
#endif /* ComM_bANY_LIGHT_CHANNEL */


/******************************************************************************/

#if (ComM_bANY_INTERNAL_CHANNEL == TRUE)
FUNC(void, COMM_CODE) ComM_vidManInternalNONESM(
                                           const NetworkHandleType ku8Channel,
                                           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                           const boolean kbLimToNoCom,
                                           #endif /* ComM_bMODE_LIMIT_ENABLE */
                                           const boolean kbActiveUR,
                                           uint32* const kpu32Cycles,
                                           const uint32 ku32MinFULLDur
                                           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                           #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                           , const boolean kbNoWakeUp
                                           #endif /* ComM_bWAKEUP_INH_ENABLE */
                                           #endif /* ComM_bMODE_LIMIT_ENABLE */
                                           )
{
    switch (ComM_au8StateMachines[ku8Channel])
    {
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    case COMM_NO_COM_NO_PENDING_REQUEST:
        vidDoNoPFULLLightNone(ku8Channel, kbLimToNoCom, kbActiveUR
                              #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                              , kbNoWakeUp
                              #endif /* ComM_bWAKEUP_INH_ENABLE */
                              );
        break;
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    case COMM_NO_COM_REQUEST_PENDING:
        if (  (  (kbActiveUR != FALSE)
               #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
               &&(kbLimToNoCom == FALSE)
               #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
               &&(kbNoWakeUp == FALSE)
               #endif /* ComM_bWAKEUP_INH_ENABLE */
               #endif /* ComM_bMODE_LIMIT_ENABLE */
              )
            ||(ComM_au8WakeUpSleepStatus[ku8Channel] == u8PASSIVE_WAKEUP)
            #if (ComM_bCOMM_DCM_ENABLED == TRUE)
            ||(ComM_abDCMActiveDiagnostic[ku8Channel] != FALSE)
            #endif /* ComM_bCOMM_DCM_ENABLED */
           )
        {
            if (ComM_abCommunicationAllowed[ku8Channel] != FALSE)
            {
                ComM_au8StateMachines[ku8Channel] =
                        COMM_FULL_COM_NETWORK_REQUESTED;
                vidDoNotify(ku8Channel, COMM_FULL_COMMUNICATION);
            }
        }
        else
        {
            ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
            /*! if reason for transition is a Limit to No Communication; then we
                should check for faulty requests and clear them */
            #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
            if(kbLimToNoCom != FALSE)
            {
                vidClearFaultyRequests(ku8Channel);
            }
            #endif /* ComM_bMODE_LIMIT_ENABLE */
        }
        break;
    case COMM_FULL_COM_NETWORK_REQUESTED:
        vidDoNETRQedLightNone(ku8Channel,
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              kbLimToNoCom,
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              kbActiveUR,
                              kpu32Cycles,
                              ku32MinFULLDur);
        break;
    case COMM_FULL_COM_READY_SLEEP:
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        if ((kbActiveUR != FALSE) && (kbLimToNoCom == FALSE))
        {
            ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
        }
        else
        {
        #endif /* ComM_bMODE_LIMIT_ENABLE */
            ComM_au8StateMachines[ku8Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
            vidDoNotify(ku8Channel, COMM_NO_COMMUNICATION);
            /*! if reason for transition is a Limit to No Communication; then we
                should check for faulty requests and clear them */
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        }
        if(kbLimToNoCom != FALSE)
        {
            vidClearFaultyRequests(ku8Channel);
        }
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        break;
    default:
        break;
    }
}
#endif /* ComM_bANY_INTERNAL_CHANNEL */


/******************************************************************************/

#if (ComM_bANY_NI_NONE == TRUE)
FUNC(void, COMM_CODE) ComM_vidManNotInternalNONESM(
                        const NetworkHandleType ku8Channel,
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        const boolean kbLimToNoCom,
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        const boolean kbActiveUR,
                        CONSTP2VAR(uint32,AUTOMATIC,COMM_APPL_DATA) kpu32Cycles,
                        const uint32 ku32MinFULLDur
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                        , const boolean kbNoWakeUp
                        #endif /* ComM_bWAKEUP_INH_ENABLE */
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        )
{
    Std_ReturnType u8Return;
    switch (ComM_au8StateMachines[ku8Channel])
    {
    case COMM_NO_COM_NO_PENDING_REQUEST:
        vidDoNoPFULLLightNone(ku8Channel,
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              kbLimToNoCom,
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              kbActiveUR
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                              , kbNoWakeUp
                              #endif /* ComM_bWAKEUP_INH_ENABLE */
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              );
        break;
    case COMM_NO_COM_REQUEST_PENDING:
        vidDoReqPLightNINone(ku8Channel,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             kbLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             kbActiveUR
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , kbNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             );
        break;
    case COMM_FULL_COM_NETWORK_REQUESTED:
        vidDoNETRQedLightNone(ku8Channel,
                              #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                              kbLimToNoCom,
                              #endif /* ComM_bMODE_LIMIT_ENABLE */
                              kbActiveUR,
                              kpu32Cycles,
                              ku32MinFULLDur);
        break;
    case COMM_FULL_COM_READY_SLEEP:
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        if ((kbActiveUR != FALSE) && (kbLimToNoCom == FALSE))
        {
            ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
        }
        else
        {
        #endif /* ComM_bMODE_LIMIT_ENABLE */
            ComM_au8StateMachines[ku8Channel] = u8TRANS_FULL_TO_NO;
            u8Return = ComM_pfu8RCOM_MODE(ku8Channel, COMM_NO_COMMUNICATION);
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                        ComM_u8MAIN_FUNCTION_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                ComM_au8StateMachines[ku8Channel] = COMM_FULL_COM_READY_SLEEP;
            }
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        }
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        break;
    default:
        break;
    }
}
#endif /* ComM_bANY_NI_NONE */


#if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)

/******************************************************************************/

FUNC(void, COMM_CODE) ComM_vidCreateFCOMReqStruct(
                             const NetworkHandleType ku8Channel,
                             ComM_UserHandleArrayType* const kpudtStruct)
{
    uint8_least u8Idx;
    uint8_least u8NoOfFComRequestors = 0;
    for (u8Idx = 0; u8Idx < u8CH_USR_REF_SIZE(ku8Channel); u8Idx++)
    {
        if (ComM_abUserRequestStatus[pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx]]
                                     != FALSE)
        {
            kpudtStruct->handleArray[u8NoOfFComRequestors] =
                    pu8CH_USR_REF_ARRAY(ku8Channel)[u8Idx];
            u8NoOfFComRequestors++;
        }
    }
    /* !Deviation: [3212] Cast is necessary if uint8 differs from uint8_least,
       this is currently not the case hence the QA C message and maybe the
       compiler warning. */
    /* PRQA S 3212 ++ */
    kpudtStruct->numberOfRequesters = (uint8)u8NoOfFComRequestors;
    /* PRQA S 3212 -- */
    ComM_abeChannelReqsUpdated[ku8Channel] = FALSE;
}
#endif /* ComM_bANY_FCOM_SRI_ENABLE */


/******************************************************************************/

/******************************************************************************/
/*                          Offered-Services Section                          */
/******************************************************************************/
/*! \Trace_To
    ComM-CDD-0126(0), ComM-CDD-0028(0), ComM-CDD-5083(0), ComM-CDD-0016(0),
    ComM-CDD-0128(0), ComM-CDD-0131(0), ComM-CDD-5272(0), ComM-CDD-5273(0),
    ComM-CDD-5033(0), ComM-CDD-5110(0), ComM-CDD-5135(0), ComM-CDD-5152(0),
    ComM-CDD-5325(0), ComM-CDD-5316(0), ComM-CDD-5309(0)*/
FUNC(void, COMM_CODE) ComM_Init(void)
{
    /*0x01*/
    uint16_least                u16Idx;
    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
    #if ((ComM_bPNC_SUPPORT == TRUE)||(ComM_bMODE_LIMIT_ENABLE == TRUE))
    Std_ReturnType        u8Return;
    #endif /* ComM_bDEV_ERROR_DETECT */
    #endif /* COMM_bPNC_SUPPORT && ComM_bMODE_LIMIT_ENABLE */
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
    uint16_least          u16ChIdx;
    uint8                 u8ChDiv;
    uint8                 u8ChMod;
    #endif /* ComM_bWAKEUP_INH_ENABLE */
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    #if (ComM_bPNC_SUPPORT == TRUE)
    uint8_least u8Idx;
    #endif /* ComM_bPNC_SUPPORT */
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE || ComM_bPNC_SUPPORT == TRUE)
    NvM_RequestResultType u8NvMResult = NVM_REQ_NOT_OK;
    #endif /* ComM_bMODE_LIMIT_ENABLE || ComM_bPNC_SUPPORT */
    /*! Initialising volatile Per-Channel Static Arrays */
    for (u16Idx = 0; u16Idx < ComM_u16NO_OF_CHANNELS; u16Idx++)
    {
        #if (ComM_bCOMM_DCM_ENABLED == TRUE)
        ComM_abDCMActiveDiagnostic[u16Idx]  = FALSE;
        #endif /* ComM_bCOMM_DCM_ENABLED */
        ComM_abCommunicationAllowed[u16Idx] = FALSE;
        ComM_au8StateMachines[u16Idx] = COMM_NO_COM_NO_PENDING_REQUEST;
        ComM_au8WakeUpSleepStatus[u16Idx] = u8NONE;
        #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
        ComM_abeChannelReqsUpdated[u16Idx] = FALSE;
        #endif /* ComM_bANY_FCOM_SRI_ENABLE */
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        /*! Initialising NoCom Limitation Array from configuration */
        ComM_abeLimitToNoComStatus[u16Idx] =
                        ComM_akstreInhibitionConfig[u16Idx].bComMNoCom;
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        #if (ComM_bPNC_SUPPORT == TRUE)
        #if (ComM_bPNC_GW_ENABLED == TRUE)
        ComM_abChGwPncReq[u16Idx] = FALSE;
        #endif /* ComM_bPNC_GW_ENABLED */
        #endif /* ComM_bPNC_SUPPORT */
    }
    /*! Initialising User Request Status Array */
    for (u16Idx = 0; u16Idx < ComM_u8NO_OF_USERS; u16Idx++)
    {
        ComM_abUserRequestStatus[u16Idx] = FALSE;
    }
    /*! Initialising non-volatile parameters (PncEnabled, Inhibition Counter,
        ComMNoWakeUp Status, and ECUGroupClassification */
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE || ComM_bPNC_SUPPORT == TRUE)
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    ComM_u16InhibitCounter = 0;
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
    u8Return =
    #else /* ComM_bDEV_ERROR_DETECT */
    (void)
    #endif /* ComM_bDEV_ERROR_DETECT */
    NvM_GetErrorStatus(ComM_udtNVM_BLOCK, &u8NvMResult);
    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
    if (u8Return != E_OK)
    {
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                              ComM_u8INIT_ID, COMM_E_ERROR_IN_PROV_SERVICE);
    }
    #endif /* ComM_bDEV_ERROR_DETECT */
    /*! If NvM_GetErrorStatus returned with NVM_REQ_OK */
    if (u8NvMResult == NVM_REQ_OK)
    {
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE && ComM_bPNC_SUPPORT == FALSE)
        /*! Shift Byte-0 in the block 8-bits by multiplying it by 0x100 */
        ComM_u16InhibitCounter = (uint16)(0x100 * ComM_au8eRamBlk[0]);
        /*! Add Byte-1 to it to get the InhibitionCounter value*/
        ComM_u16InhibitCounter = ComM_u16InhibitCounter + ComM_au8eRamBlk[1];
        /*! Get ECUGroupClassification Value from Byte-2 */
        ComM_u8eECUGClassification = (0x03 & ComM_au8eRamBlk[2]);
        /*! Get the channels' ComMNoWakeUp Status from the rest of the Block
            Bytes */
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        for (u16ChIdx = 0; u16ChIdx < ComM_u16NO_OF_CHANNELS; u16ChIdx++)
        {
            u8ChDiv = (uint8)(u16ChIdx/8);
            u8ChMod = (uint8)(u16ChIdx%8);
            if (((ComM_au8eRamBlk[3+u8ChDiv] >> (u8ChMod)) & 0x01) > 0)
            {
                ComM_abeWakeUpInibitStatus[u16ChIdx] = TRUE;
            }
            else
            {
                ComM_abeWakeUpInibitStatus[u16ChIdx] = FALSE;
            }
        }
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #elif ((ComM_bMODE_LIMIT_ENABLE == TRUE && ComM_bPNC_SUPPORT == TRUE))
        /*! Get ComMPncEnabled Value from Byte-0 */
        ComM_bePncEnabled = (boolean)(ComM_au8eRamBlk[0]);
        /*! Shift Byte-1 in the block 8-bits by multiplying it by 0x100 */
        ComM_u16InhibitCounter = (uint16)(0x100 * ComM_au8eRamBlk[1]);
        /*! Add Byte-2 to it to get the InhibitionCounter value*/
        ComM_u16InhibitCounter = ComM_u16InhibitCounter + ComM_au8eRamBlk[2];
        /*! Get ECUGroupClassification Value from Byte-3 */
        ComM_u8eECUGClassification = (0x03 & ComM_au8eRamBlk[3]);
        /*! Get the channels' ComMNoWakeUp Status from the rest of the Block
            Bytes */
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        for (u16ChIdx = 0; u16ChIdx < ComM_u16NO_OF_CHANNELS; u16ChIdx++)
        {
            u8ChDiv = (uint8)(u16ChIdx/8);
            u8ChMod = (uint8)(u16ChIdx%8);
            if (((ComM_au8eRamBlk[4+u8ChDiv] >> (u8ChMod)) & 0x01) > 0)
            {
                ComM_abeWakeUpInibitStatus[u16ChIdx] = TRUE;
            }
            else
            {
                ComM_abeWakeUpInibitStatus[u16ChIdx] = FALSE;
            }
        }
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        #elif (ComM_bMODE_LIMIT_ENABLE == FALSE && ComM_bPNC_SUPPORT == TRUE)
        /*! Get ComMPncEnabled Value from Byte-0 */
        ComM_bePncEnabled = (boolean)(ComM_au8eRamBlk[0]);
        #endif /* ComM_bMODE_LIMIT_ENABLE && ComM_bPNC_SUPPORT */
    }
    /*! Else (NvM_GetErrorStatus returned with something else) */
    else
    {
        /*! Initialise the configurations from memory */
        #if (ComM_bPNC_SUPPORT == TRUE)
        ComM_bePncEnabled = ComM_bPNC_ENABLED;
        #endif /* ComM_bPNC_SUPPORT == TRUE */
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        ComM_u8eECUGClassification = ComM_u8ECUG_CLASSIFICATION;
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        for (u16Idx = 0; u16Idx < ComM_u16NO_OF_CHANNELS; u16Idx++)
        {
            ComM_abeWakeUpInibitStatus[u16Idx] =
                    ComM_akstreInhibitionConfig[u16Idx].bComMNoWakeup;
        }
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
    }
    #endif /* ComM_bMODE_LIMIT_ENABLE || ComM_bPNC_SUPPORT */
    #if (ComM_bPNC_SUPPORT == TRUE)
    /*!Initialize all the PNC's states to PNC_NO_COMMUNICATION.*/
    for (u8Idx = 0; u8Idx < ComM_u8NO_OF_PNCS; u8Idx++)
    {
        ComM_au8PncState[u8Idx] = PNC_NO_COMMUNICATION;
    }
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    for (u8Idx = 0; u8Idx < ComM_u8NO_SIZE_OF_SIG_ARR; u8Idx++)
    {
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR > 1*/
        ComM_au8T_SIG(ComM_au8eAggregSignal, u8Idx) = 0;
        ComM_au8T_SIG(ComM_au8eTxAgg, u8Idx) = 0;
        #if (ComM_bPNC_GW_ENABLED == TRUE)
        ComM_au8T_SIG(ComM_au8eTxERAAgg, u8Idx) = 0;
        ComM_au8T_SIG(ComM_au8eAggregERASig, u8Idx) = 0;
        #endif /* ComM_bPNC_GW_ENABLED */
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    }
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR > 1*/
    #endif /* ComM_bPNC_SUPPORT == TRUE */
    ComM_udteInitStatus = COMM_INIT;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0129(0), ComM-CDD-5121(0), ComM-CDD-5041(0), ComM-CDD-5042(0),
    ComM-CDD-5269(0), ComM-CDD-5109(0), ComM-CDD-5120(0), ComM-CDD-5186(0),
    ComM-CDD-5318(0) */
FUNC(void, COMM_CODE) ComM_DeInit(void)
{
    /*0x02*/
    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
    uint16_least   u16ChIdx;
    uint8          u8ChDiv;
    uint8          u8ChMod;
    #endif /* ComM_bWAKEUP_INH_ENABLE */
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE || ComM_bPNC_SUPPORT == TRUE)
    #if (ComM_bNVM_RAM_BLOCK_API == STD_ON)
    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
    Std_ReturnType u8Return;
    #endif /* ComM_bDEV_ERROR_DETECT */
    #endif /* NVM_SET_RAM_BLOCK_STATUS_API */
    #endif /*ComM_bMODE_LIMIT_ENABLE || ComM_bPNC_SUPPORT */

    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                              ComM_u8DE_INIT_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE || ComM_bPNC_SUPPORT == TRUE)
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE && ComM_bPNC_SUPPORT == FALSE)
        /*! Write InhibitionCounter in the Ram Block, byte by byte, MSB first */
        ComM_au8eRamBlk[0] = (uint8)(ComM_u16InhibitCounter / 0x100);
        ComM_au8eRamBlk[1] = (uint8)(ComM_u16InhibitCounter % 0x100);
        /*! Write ECUGroupClassification */
        ComM_au8eRamBlk[2] = 0x03 & ComM_u8eECUGClassification;
        /*! Write channels' ComMNoWakeUp Status, bit by bit, bit 0 of byte 3
            corresponds to channel 0, and bit 0 of byte 4 corresponds to channel
            8 */
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        for (u16ChIdx = 0; u16ChIdx < ComM_u16NO_OF_CHANNELS; u16ChIdx++)
        {
            u8ChDiv = (uint8)(u16ChIdx/8);
            u8ChMod = (uint8)(u16ChIdx%8);
            if (u8ChMod == 0)
            {
                ComM_au8eRamBlk[3+u8ChDiv] = 0;
            }
            if (ComM_abeWakeUpInibitStatus[u16ChIdx] != FALSE)
            {
                ComM_au8eRamBlk[3+u8ChDiv] =
                     ((uint8)(1 << (u8ChMod))) | ComM_au8eRamBlk[3+u8ChDiv];
            }
        }
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #elif (ComM_bMODE_LIMIT_ENABLE == TRUE && ComM_bPNC_SUPPORT == TRUE)
        ComM_au8eRamBlk[0] = (uint8)(ComM_bePncEnabled);
        /*! Write InhibitionCounter in the Ram Block, byte by byte, MSB first */
        ComM_au8eRamBlk[1] = (uint8)(ComM_u16InhibitCounter / 0x100);
        ComM_au8eRamBlk[2] = (uint8)(ComM_u16InhibitCounter % 0x100);
        /*! Write ECUGroupClassification */
        ComM_au8eRamBlk[3] = 0x03 & ComM_u8eECUGClassification;
        /*! Write channels' ComMNoWakeUp Status, bit by bit, bit 0 of byte 3
            corresponds to channel 0, and bit 0 of byte 4 corresponds to channel
            8 */
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        for (u16ChIdx = 0; u16ChIdx < ComM_u16NO_OF_CHANNELS; u16ChIdx++)
        {
            u8ChDiv = (uint8)(u16ChIdx/8);
            u8ChMod = (uint8)(u16ChIdx%8);
            if (u8ChMod == 0)
            {
                ComM_au8eRamBlk[4+u8ChDiv] = 0;
            }
            if (ComM_abeWakeUpInibitStatus[u16ChIdx] != FALSE)
            {
                ComM_au8eRamBlk[4+u8ChDiv] =
                     ((uint8)(1 << (u8ChMod))) | ComM_au8eRamBlk[4+u8ChDiv];
            }
        }
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #elif (ComM_bMODE_LIMIT_ENABLE == FALSE && ComM_bPNC_SUPPORT == TRUE)
        ComM_au8eRamBlk[0] = (uint8)(ComM_bePncEnabled);
        #endif /* ComM_bMODE_LIMIT_ENABLE || ComM_bPNC_SUPPORT */
        #if (ComM_bNVM_RAM_BLOCK_API == STD_ON)
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        u8Return =
        #else
        (void)
        #endif /* ComM_bDEV_ERROR_DETECT */
        NvM_SetRamBlockStatus(ComM_udtNVM_BLOCK, TRUE);
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        if (u8Return != E_OK)
        {
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                    ComM_u8DE_INIT_ID, COMM_E_ERROR_IN_PROV_SERVICE);
        }
        #endif /* ComM_bDEV_ERROR_DETECT */
        #endif /* NVM_SET_RAM_BLOCK_STATUS_API */
        #endif /* ComM_bMODE_LIMIT_ENABLE  || ComM_bPNC_SUPPORT*/
        ComM_udteInitStatus = COMM_UNINIT;
    }
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0132(0), ComM-CDD-5043(0), ComM-CDD-5122(0), ComM-CDD-5044(0),
    ComM-CDD-5177(0), ComM-CDD-5205(0), ComM-CDD-5176(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetState(
                           NetworkHandleType Channel,
                           P2VAR(ComM_StateType,AUTOMATIC,COMM_APPL_DATA) State)
{
    /*0x34*/
    Std_ReturnType u8Return = E_OK;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                              ComM_u8GET_STATE_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else if ((State == NULL_PTR)||(Channel >= ComM_u16NO_OF_CHANNELS))
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                              ComM_u8GET_STATE_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        /*Clarification:
          Transient states are necessary for waiting for BusSm mode indications
          and/or Nm indications, however the user of ComM_GetState shall have no
          knowledge of them*/
        /*! If state is one of the main sub-states; return it directly */
        if (ComM_au8StateMachines[Channel] <= COMM_SILENT_COM)
        {
            *State = ComM_au8StateMachines[Channel];
        }
        /*! otherwise its a transient state between two main states, so return
            the state the channel was moving FROM. */
        else if (  (ComM_au8StateMachines[Channel] == u8TRANS_NO_TO_FULL)
                 ||(ComM_au8StateMachines[Channel] == u8TRANS_NO_TO_FULL_NR))
        {
            *State = COMM_NO_COM_REQUEST_PENDING;
        }
        else if (  (ComM_au8StateMachines[Channel] == u8TRANS_FULL_TO_NO)
                 ||(ComM_au8StateMachines[Channel] == u8TRANS_FULL_TO_SILENT))
        {
            *State = COMM_FULL_COM_READY_SLEEP;
        }
        else
        {
            *State = COMM_SILENT_COM;
        }
    }
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0133(0), ComM-CDD-5213(0), ComM-CDD-5178(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus(
                     P2VAR(ComM_InitStatusType,AUTOMATIC,COMM_APPL_DATA) Status)
{
    /*0x03*/
    Std_ReturnType u8Return = E_OK;
    if (Status == NULL_PTR)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_STATUS_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        *Status = ComM_udteInitStatus;
    }
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0134(0), ComM-CDD-5047(0), ComM-CDD-5048(0), ComM-CDD-5123(0),
    ComM-CDD-5179(0), ComM-CDD-5191(0) */
#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus(
               NetworkHandleType Channel,
               P2VAR(ComM_InhibitionStatusType,AUTOMATIC,COMM_APPL_DATA) Status)
{
    /*0x04*/
    Std_ReturnType            u8Return = E_OK;
    /*! create a temporary variable to hold the Inhibition Status; initialise it
        with zero */
    ComM_InhibitionStatusType u8ReurnedStatus = 0;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_INHIBITION_ST_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else if ((Status == NULL_PTR)||(Channel >= ComM_u16NO_OF_CHANNELS))
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_INHIBITION_ST_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        /*actual code here*/
        /*! check ComMNoCom status of the channel along with ECU Group
            Classification; if the limit to no communication is active; set the
            temporary variable to 2 (i.e. set the second bit) */
        if ((bCHK_LIMNOCOM_GC == 1) &&
                (ComM_abeLimitToNoComStatus[Channel] != FALSE))
        {
            u8ReurnedStatus = 2;
        }
        /*! check ComMNoWakeup status of the channel along with ECU Group
            Classification; if the wake-up limitation active; increment the
            temporary variable by 1 (i.e. set the first bit whether a limit to
            no communication was detected or not) */
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        if ((bCHK_NOWAKEUP_GC == 1) &&
                (ComM_abeWakeUpInibitStatus[Channel] != FALSE))
        {
            u8ReurnedStatus += 1;
        }
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        *Status = u8ReurnedStatus;
    }
    return u8Return;
}
#endif /* ComM_bMODE_LIMIT_ENABLE */


/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0135(0), ComM-CDD-0076(0), ComM-CDD-5093(0), ComM-CDD-5074(0),
    ComM-CDD-5078(0), ComM-CDD-5034(0), ComM-CDD-5164(0), ComM-CDD-5031(0),
    ComM-CDD-5032(0), ComM-CDD-5104(0), ComM-CDD-5096(0), ComM-CDD-5075(0),
    ComM-CDD-5103(0), ComM-CDD-5105(0), ComM-CDD-5113(0), ComM-CDD-5173(0),
    ComM-CDD-5170(0), ComM-CDD-5271(0), ComM-CDD-5049(0), ComM-CDD-5089(0),
    ComM-CDD-5124(0), ComM-CDD-5185(0), ComM-CDD-5050(0), ComM-CDD-5201(0),
    ComM-CDD-5306(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode(ComM_UserHandleType User,
                                                    ComM_ModeType ComMode)
{
    /*0x05*/
    Std_ReturnType    u8Return = E_OK;
    #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
    uint16_least      u16Idx;
    NetworkHandleType u8TChannel;
    #endif /* ComM_bANY_FCOM_SRI_ENABLE */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8REQUEST_COM_MODE_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else if (  ((ComMode != COMM_NO_COMMUNICATION) &&
                (ComMode != COMM_FULL_COMMUNICATION))
             ||(User >= ComM_u8NO_OF_USERS))
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8REQUEST_COM_MODE_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        /*actual code here*/
        /*! Case of COMM_NO_COMMUNICATION request (i.e. releasing a request) */
        if (ComMode == COMM_NO_COMMUNICATION)
        {
            /*! if user's original request is COMM_FULL_COMMUNICATION set the
                channelReqsUpdated status to TRUE for each channel mapped to the
                User. */
            /*! \note it must be known that the previously described
                      functionality is only available if there is a single
                      fullComRequestors SenderReceiverInterface enabled. */
            #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
            if (ComM_abUserRequestStatus[User] != COMM_NO_COMMUNICATION)
            {
                for (u16Idx=0; u16Idx<u16USR_CH_REF_SIZE(User); u16Idx++)
                {
                    u8TChannel = pu8USR_CH_REF_ARRAY(User)[u16Idx];
                    ComM_abeChannelReqsUpdated[u8TChannel] = TRUE;
                }
            }
            #endif /* ComM_bANY_FCOM_SRI_ENABLE */
            /*! Set the User's value in the ComM_abUserRequestStatus array to
                FALSE, channels' Main Functions will handle the rest. */
            ComM_abUserRequestStatus[User] = FALSE;
        }
        else /*! case COMM_FULL_COMMUNICATION is requested; call
                 u8HandleFComReq() to handle the request. */
        {
            u8Return = u8HandleFComReq(User);
        }
    }
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    if (u8Return == COMM_E_MODE_LIMITATION)
    {
        vidIncrInhCounter();
    }
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0137(0), ComM-CDD-5051(0), ComM-CDD-5125(0), ComM-CDD-5052(0),
    ComM-CDD-0138(0), ComM-CDD-5202(0), ComM-CDD-5203(0), ComM-CDD-5127(0), */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode(
                          ComM_UserHandleType User,
                          P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode)
{
    /*0x06*/
    Std_ReturnType    u8Return = E_OK;
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    uint16_least      u16Idx;
    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
    boolean           bSilentDetected = FALSE;
    #endif /* ComM_bWAKEUP_INH_ENABLE */
    boolean           bBreak = FALSE;
    NetworkHandleType u8TChannel;
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_MAX_COM_MODE_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else if ((ComMode == NULL_PTR) || (User >= ComM_u8NO_OF_USERS))
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_MAX_COM_MODE_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        /*! If ECUGroupClassification is set to zero, then there is no active
            mode limitations, so return COMM_FULL_COMMUNICATION. */
        if (ComM_u8eECUGClassification == 0)
        {
            *ComMode = COMM_FULL_COMMUNICATION;
        }
        else
        {
            /*! otherwise loop on user's channels and for each channel: */
            for (u16Idx=0;(  (u16Idx<(u16USR_CH_REF_SIZE(User)))
                           &&(bBreak == FALSE)); u16Idx++)
            {
                /*! test if a ComMNoCom limitation is active, if TRUE return
                    COMM_NO_COMMUNICATION, and break the loop. */
                u8TChannel = pu8USR_CH_REF_ARRAY(User)[u16Idx];
                if ((bCHK_LIMNOCOM_GC == 1)
                        &&(ComM_abeLimitToNoComStatus[u8TChannel] != FALSE))
                {
                    bBreak = TRUE;
                    *ComMode = COMM_NO_COMMUNICATION;
                }
                /*! otherwise check if a ComMNoWakeup limitation is active and
                    the channel is not already in COMM_FULL_COMMUNICATION. */
                #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                else if ((bSilentDetected == FALSE) &&
                         (bCHK_NOWAKEUP_GC == 1) &&
                         (ComM_abeWakeUpInibitStatus[u8TChannel] != FALSE) &&
                         (ComM_au8StateMachines[u8TChannel] !=
                                COMM_FULL_COM_NETWORK_REQUESTED) &&
                         (ComM_au8StateMachines[u8TChannel] !=
                                COMM_FULL_COM_READY_SLEEP))
                {
                    /*! If TRUE set a flag that COMM_SILENT_COMMUNICATION was
                        set as a MaxComMode so far, and continue the loop. */
                    bSilentDetected = TRUE;
                }
                #endif /* ComM_bWAKEUP_INH_ENABLE */
                else
                {
                    /*! Otherwise continue the loop */
                }
            }
            /*! after finishing the loop, check that it was not broken. */
            if (bBreak == FALSE)
            {
                #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                if (bSilentDetected != FALSE)
                {
                    /*! if TRUE and the COMM_SILENT_COMMUNICATION flag was set
                        then return COMM_SILENT_COMMUNICATION */
                    *ComMode = COMM_SILENT_COMMUNICATION;
                }
                else
                {

                    /*! if the flag was not set then return
                        COMM_FULL_COMMUNICATION */
                #endif /* ComM_bWAKEUP_INH_ENABLE */
                    *ComMode = COMM_FULL_COMMUNICATION;
                #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                }
                #endif /* ComM_bWAKEUP_INH_ENABLE */
            }
        }

        #else  /* ComM_bMODE_LIMIT_ENABLE */
        *ComMode = COMM_FULL_COMMUNICATION;
        #endif /* ComM_bMODE_LIMIT_ENABLE */
    }
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0140(0), ComM-CDD-5181(0), ComM-CDD-5053(0), ComM-CDD-5126(0),
    ComM-CDD-5054(0), ComM-CDD-5206(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode(
                          ComM_UserHandleType User,
                          P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode)
{
    /*0x07*/
    Std_ReturnType u8Return = E_OK;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_REQUESTED_COM_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else if ((ComMode == NULL_PTR) || (User >= ComM_u8NO_OF_USERS))
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_REQUESTED_COM_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        /*! Check the User's corresponding value in ComM_abUserRequestStatus,
            if TRUE then return COMM_FULL_COMMUNICATION, if FALSE return
            COMM_NO_COMMUNICATION */
        if (ComM_abUserRequestStatus[User] != FALSE)
        {
            *ComMode = COMM_FULL_COMMUNICATION;
        }
        else
        {
            *ComMode = COMM_NO_COMMUNICATION;
        }
    }
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0142(0), ComM-CDD-5055(0), ComM-CDD-5056(0), ComM-CDD-5207(0),
    ComM-CDD-5116(0), ComM-CDD-5182(0), ComM-CDD-5285(0), ComM-CDD-0143(0),
    ComM-CDD-0015(0), ComM-CDD-0338(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode(
                          ComM_UserHandleType User,
                          P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode)
{
    /*0x08*/
    Std_ReturnType    u8Return = E_OK;
    uint16_least      u16Idx;
    NetworkHandleType u8TChannel;
    ComM_ModeType     u8TempComMode;
    boolean           bSilentDetected = FALSE;
    boolean           bBreak = FALSE;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_CURRENT_COM_M_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }

    else if ((ComMode == NULL_PTR) || (User >= ComM_u8NO_OF_USERS))
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8GET_CURRENT_COM_M_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        /*! Loop on User's Channels */
        u8TempComMode = COMM_NO_COMMUNICATION;
        for (u16Idx=0;(u16Idx<(u16USR_CH_REF_SIZE(User)))
                          && (bBreak==FALSE); u16Idx++)
        {
            u8TChannel = pu8USR_CH_REF_ARRAY(User)[u16Idx];
            /*! call its BusSM GetCurrentComMode Service */
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            u8Return =
            #else
            (void)
            #endif /* ComM_bDEV_ERROR_DETECT */
            ComM_pfu8GCCOM_MODE(u8TChannel, &u8TempComMode);
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            if (u8Return != E_OK)
            {
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                     ComM_u8GET_CURRENT_COM_M_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                u8TempComMode = COMM_NO_COMMUNICATION;
            }
            #endif /* ComM_bDEV_ERROR_DETECT */
            if (u8TempComMode == COMM_NO_COMMUNICATION)
            {
                /*! if COMM_NO_COMMUNICATION was returned, return
                    COMM_NO_COMMUNICATION, and break the loop. */
                *ComMode = COMM_NO_COMMUNICATION;
                bBreak = TRUE;
            }
            else if (u8TempComMode == COMM_SILENT_COMMUNICATION)
            {
                /*! else if COMM_SILENT_COMMUNICATION was returned, set a flag
                    that COMM_SILENT_COMMUNICATION was set as the Maximum
                    ComMode so far, and continue the loop. */
                bSilentDetected = TRUE;
            }
            else
            {
                /*! else simply continue */
            }
        }
        /*! after finishing the loop, check that it was not broken. */
        if (bBreak == FALSE)
        {
            if (bSilentDetected != FALSE)
            {
                /*! if TRUE and the COMM_SILENT_COMMUNICATION flag was set
                    then return COMM_SILENT_COMMUNICATION */
                *ComMode = COMM_SILENT_COMMUNICATION;
            }
            else
            {
                /*! if the flag was not set then return
                    COMM_FULL_COMMUNICATION */
                *ComMode = COMM_FULL_COMMUNICATION;
            }
        }
    }
    return u8Return;
}

/******************************************************************************/

#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
#if (ComM_bWAKEUP_INH_ENABLE == TRUE)
/*! \Trace_To
    ComM-CDD-0145(0), ComM-CDD-0146(0), ComM-CDD-5057(0), ComM-CDD-5128(0),
    ComM-CDD-5058(0), ComM-CDD-5192(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp(NetworkHandleType Channel,
                                                   boolean Status)
{
    /*0x09*/
    Std_ReturnType u8Return = E_OK;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8PREVENT_WAKE_UP_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else if (  (Channel >= ComM_u16NO_OF_CHANNELS)
             #if (ComM_bDEV_ERROR_DETECT == STD_ON)
             ||((Status != TRUE) && (Status != FALSE))
             #endif /* ComM_bDEV_ERROR_DETECT */
            )
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8PREVENT_WAKE_UP_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        /*! Set the Channel's value in ComM_abWakeUpInibitStatus to Status. */
        ComM_abeWakeUpInibitStatus[Channel] = Status;
    }
    return u8Return;
}
#endif /* ComM_bWAKEUP_INH_ENABLE */

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0147(0), ComM-CDD-0078(0), ComM-CDD-0148(0), ComM-CDD-5111(0),
    ComM-CDD-5112(0), ComM-CDD-5059(0), ComM-CDD-5129(0), ComM-CDD-5157(0),
    ComM-CDD-5193(0), ComM-CDD-0055(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode(
                                            NetworkHandleType Channel,
                                            boolean Status)
{
    /*0x0B*/
    Std_ReturnType u8Return = E_OK;
    #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
    boolean        bBool;
    #endif /* ComM_bANY_FCOM_SRI_ENABLE */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8LIMIT_CHANNEL_TO_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else if (  (Channel >= ComM_u16NO_OF_CHANNELS)
             #if (ComM_bDEV_ERROR_DETECT == STD_ON)
             ||((Status != TRUE) && (Status != FALSE))
             #endif /* ComM_bDEV_ERROR_DETECT */
            )
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8LIMIT_CHANNEL_TO_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        /*! if Status is TRUE */
        if (Status != FALSE)
        {
        /*! ensure channel is in COMM_FULL_COM_NETWORK_REQUESTED*/
            if (ComM_au8StateMachines[Channel]==COMM_FULL_COM_NETWORK_REQUESTED)
            {
                /*! Set the Channel's value in ComM_abLimitToNoComStatus
                    to TRUE. */
                ComM_abeLimitToNoComStatus[Channel] = TRUE;
                /*! switch channel to COMM_FULL_COM_READY_SLEEP if there is no
                    active diagnostic session. */
                if (  (bCHK_LIMNOCOM_GC == 1)
                    #if (ComM_bCOMM_DCM_ENABLED == TRUE)
                    &&(ComM_abDCMActiveDiagnostic[Channel] == FALSE)
                    #endif /* ComM_bCOMM_DCM_ENABLED */
                   )
                {
                    ComM_au8StateMachines[Channel] = COMM_FULL_COM_READY_SLEEP;
                    ComM_au8WakeUpSleepStatus[Channel] = u8ENTER_READY_SLEEP;
                }
            }
            else
            {
                u8Return = E_NOT_OK;
            }
        }
        /*! else (i.e. Status is FALSE) Set the Channel's value in
            ComM_abLimitToNoComStatus to FALSE. */
        else
        {
            ComM_abeLimitToNoComStatus[Channel] = FALSE;
            #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
            bBool = ComM_bEvalChUserRequest(Channel);
            if (bBool != FALSE)
            {
                ComM_abeChannelReqsUpdated[Channel] = TRUE;
            }
            #endif /* ComM_bANY_FCOM_SRI_ENABLE */
        }
    }
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0149(0), ComM-CDD-0150(0), ComM-CDD-5061(0), ComM-CDD-5062(0),
    ComM-CDD-5130(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode(boolean Status)
{
    /*0x0C*/
    Std_ReturnType u8Return = E_OK;
    uint16_least   u16Idx;
    #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
    boolean        bBool;
    #endif /* ComM_bANY_FCOM_SRI_ENABLE */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8LIMIT_ECU_TO_NO_C_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
    else if ((Status != TRUE) && (Status != FALSE))
    {
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8LIMIT_ECU_TO_NO_C_ID, COMM_E_WRONG_PARAMETERS);
        u8Return = E_NOT_OK;
    }
    #endif /* ComM_bDEV_ERROR_DETECT */
    else
    {
        /*! if Status is TRUE */
        if (Status != FALSE)
        {
            /*! loop on all channels*/
            for (u16Idx = 0; u16Idx<ComM_u16NO_OF_CHANNELS; u16Idx++)
            {
                /*! ensure channel is in COMM_FULL_COM_NETWORK_REQUESTED*/
                if (ComM_au8StateMachines[u16Idx]==
                           COMM_FULL_COM_NETWORK_REQUESTED)
                {
                    /*! Set the Channel's value in ComM_abLimitToNoComStatus
                        to TRUE. */
                    ComM_abeLimitToNoComStatus[u16Idx] = TRUE;
                    /*! switch channel to COMM_FULL_COM_READY_SLEEP if there is
                        no active diagnostic session */
                    if (  (bCHK_LIMNOCOM_GC == 1)
                        #if (ComM_bCOMM_DCM_ENABLED == TRUE)
                        &&(ComM_abDCMActiveDiagnostic[u16Idx] == FALSE)
                        #endif /* ComM_bCOMM_DCM_ENABLED */
                       )
                    {
                        ComM_au8StateMachines[u16Idx]=COMM_FULL_COM_READY_SLEEP;
                        ComM_au8WakeUpSleepStatus[u16Idx]=u8ENTER_READY_SLEEP;
                    }
                }
            }
        }
        else
        {
            /*! else (i.e. Status is FALSE) Set the all values of
                        ComM_abLimitToNoComStatus to FALSE. */
            for (u16Idx = 0; u16Idx<ComM_u16NO_OF_CHANNELS; u16Idx++)
            {
                ComM_abeLimitToNoComStatus[u16Idx] = FALSE;
                #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
                bBool = ComM_bEvalChUserRequest((uint8)u16Idx);
                if (bBool != FALSE)
                {
                    ComM_abeChannelReqsUpdated[u16Idx] = TRUE;
                }
                #endif /* ComM_bANY_FCOM_SRI_ENABLE */
            }
        }
    }
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0151(0), ComM-CDD-0152(0), ComM-CDD-5063(0), ComM-CDD-5131(0),
    ComM-CDD-5064(0), ComM-CDD-5183(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter(uint16* CounterValue)
{
    /*0x0D*/
    Std_ReturnType u8Return = E_OK;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8READ_INHIBIT_COUN_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else if (CounterValue == NULL_PTR)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8READ_INHIBIT_COUN_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = E_NOT_OK;
    }
    else
    {
        /*! Return ComM_u16InhibitCounter in the CounterValue pointer. */
        /* PRQA S 3141 ++ */
        SchM_Enter_ComM_CounterSec();
        /* PRQA S 3141 -- */
        *CounterValue = ComM_u16InhibitCounter;
        /* PRQA S 3141 ++ */
        SchM_Exit_ComM_CounterSec();
        /* PRQA S 3141 -- */
    }
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0153(0), ComM-CDD-0154(0), ComM-CDD-5065(0), ComM-CDD-5132(0),
    ComM-CDD-5066(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter(void)
{
    /*0x0E*/
    Std_ReturnType u8Return = E_OK;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
#if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8RESET_INHIBIT_COU_ID, COMM_E_NOT_INITED);
#endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else
    {
        /*! Set ComM_u16InhibitCounter to 0. */
        /* PRQA S 3141 ++ */
        SchM_Enter_ComM_CounterSec();
        /* PRQA S 3141 -- */
        ComM_u16InhibitCounter = 0;
        /* PRQA S 3141 ++ */
        SchM_Exit_ComM_CounterSec();
        /* PRQA S 3141 -- */
    }
    return u8Return;
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0155(0), ComM-CDD-5067(0), ComM-CDD-5133(0), ComM-CDD-5068(0),
    ComM-CDD-5298(0) */
FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification(
                                        ComM_InhibitionStatusType Status)
{
    /*0x0F*/
    Std_ReturnType u8Return = E_OK;
    #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
    uint16_least   u16Idx;
    #endif /* ComM_bANY_FCOM_SRI_ENABLE */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8SET_ECU_GROUP_CLA_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
        u8Return = COMM_E_UNINIT;
    }
    else
    {
        #if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
        /*! check if this will result in lifting a ComMNoCom mode limitation */
        if ((bCHK_LIMNOCOM_GC == 1) && ((Status&0x02)==0))
        {
            /*! for all channels that had an active mode limitation; update the
                ComM_abeChannelReqsUpdated value of the channel */
            for (u16Idx = 0; u16Idx < ComM_u16NO_OF_CHANNELS; u16Idx++)
            {
                if (ComM_abeLimitToNoComStatus[u16Idx] != FALSE)
                {
                    ComM_abeChannelReqsUpdated[u16Idx] = TRUE;
                }
            }
        }
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        /*! check if this will result in lifting a ComMNoWakeUp mode limitation
        */
        if ((bCHK_NOWAKEUP_GC == 1) && ((Status&0x01)==0))
        {
            /*! for all channels that had an active mode limitation; update the
                ComM_abeChannelReqsUpdated value of the channel */
            for (u16Idx = 0; u16Idx < ComM_u16NO_OF_CHANNELS; u16Idx++)
            {
                if ((ComM_abeWakeUpInibitStatus[u16Idx] != FALSE)
                        && (ComM_au8StateMachines[u16Idx]!=
                                COMM_FULL_COM_NETWORK_REQUESTED)
                        && (ComM_au8StateMachines[u16Idx] !=
                                COMM_FULL_COM_READY_SLEEP)
                   )
                {
                    ComM_abeChannelReqsUpdated[u16Idx] = TRUE;
                }
            }
        }
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bANY_FCOM_SRI_ENABLE */
        /*! Set ComM_u8ECUGClassification to Status */
        ComM_u8eECUGClassification = Status;
    }
    return u8Return;
}
#endif /* ComM_bMODE_LIMIT_ENABLE */


/******************************************************************************/
/*                           Nm Indications Section                           */
/******************************************************************************/


#if ((ComM_bANY_FULL_CHANNEL == TRUE)||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
/*! \Trace_To
    ComM-CDD-0161(0), ComM-CDD-5119(0), ComM-CDD-5254(0), ComM-CDD-5259(0),
    ComM-CDD-5140(0), ComM-CDD-5225(0), ComM-CDD-5215(0), ComM-CDD-5292(0),
    ComM-CDD-5194(0), ComM-CDD-5286(0), ComM-CDD-5305(0) */
FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication(NetworkHandleType Channel)
{
    /*0x15*/
    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
    Std_ReturnType u8Return;
    Std_ReturnType  udtTReturn;
    #endif /* ComM_bDEV_ERROR_DETECT */
    ComM_ModeType  u8TempComMode;
    boolean        bCallPassiveStartup = FALSE;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_NETWORK_START_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (Channel >= ComM_u16NO_OF_CHANNELS)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_NETWORK_START_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
    /*actual code here*/
        switch (ComM_au8StateMachines[Channel])
        {
        case COMM_FULL_COM_NETWORK_REQUESTED:
        case COMM_FULL_COM_READY_SLEEP:
            /*! if already in COMM_FULL_COM_NETWORK_REQUESTED or
                COMM_FULL_COM_READY_SLEEP, switch to
                COMM_FULL_COM_NETWORK_REQUESTED and set the flag to call
                Nm_PassiveStartUp(). */
            /*! \note the flag trick is to get around the
                      number-of-function-calls metric and prevent it from
                      getting out of bounds. */
            ComM_au8StateMachines[Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
            bCallPassiveStartup = TRUE;
            break;
            /*! else if in a transient state to COMM_FULL_COMMUNICATION: */
        case u8TRANS_NO_TO_FULL:
        case u8TRANS_SILENT_TO_FULL:
            if (ComM_au8WakeUpSleepStatus[Channel] == u8ACTIVE_WAKEUP)
            {
                /*! Get the Bus Current ComMode to verify whether the Indication
                    has been received or not. */
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                u8Return = ComM_pfu8GCCOM_MODE(Channel, &u8TempComMode);
                if (u8Return != E_OK)
                {
                    (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                            ComM_u8NM_NETWORK_START_ID,
                            COMM_E_ERROR_IN_PROV_SERVICE);
                }
                #else  /* ComM_bDEV_ERROR_DETECT */
                (void)ComM_pfu8GCCOM_MODE(Channel, &u8TempComMode);
                #endif /* ComM_bDEV_ERROR_DETECT */
                if ((u8TempComMode == COMM_FULL_COMMUNICATION)
                    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                     && (u8Return == E_OK)
                    #endif /* ComM_bDEV_ERROR_DETECT */
                   )
                {
                    /*! this means that the BusSm Mode indication was received
                        already, and thus Nm_NetworkRequest() has already been
                        called, a call to Nm_PassiveStartUp() is still necessary
                        but if the NetworkMode() callback was received and
                        ComM_au8WakeUpSleepStatus was u8PASSIVE_WAKEUP it will
                        result in a second call to Nm_NetworkRequest() due to
                        the active user request which is unnecessary, so we
                        leave it as u8ACTIVE_WAKEUP to prevent the second call
                        to Nm_NetworkRequest() */
                    bCallPassiveStartup = TRUE;
                }
                else
                {
                    /*! The call indication has not yet been received, assign
                        u8PASSIVE_WAKEUP and leave the call to
                        Nm_PassiveStartUp() to the indication. */
                    ComM_au8WakeUpSleepStatus[Channel] = u8PASSIVE_WAKEUP;
                }
            }
            break;
        default:
            /*! otherwise begin a transition to COMM_FULL_COMMUNICATION
                immediately by:\n
                1- Setting the the channel's value in ComM_au8StateMachines to
                   the appropriate transient.\n
                2- Setting the channel's value in ComM_au8WakeUpSleepStatus to
                   u8PASSIVE_WAKEUP.\n
                3- Request COMM_FULL_COMMUNICATION from the channel's BusSM.\n
                This is done by making a call to vidGoToFCom(). */
            vidGoToFCom(Channel);
            break;
        }
        if (bCallPassiveStartup != FALSE)
        {
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            udtTReturn =
            #else
            (void)
            #endif /* ComM_bDEV_ERROR_DETECT */
            Nm_PassiveStartUp(Channel);
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            if (udtTReturn == E_NOT_OK)
            {
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                      ComM_u8NM_NETWORK_START_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            }
            #endif /* ComM_bDEV_ERROR_DETECT */
        }
    }
}

/******************************************************************************/


/*! \Trace_To
    ComM-CDD-0163(0), ComM-CDD-0042(0), ComM-CDD-5141(0), ComM-CDD-5226(0),
    ComM-CDD-5224(0), ComM-CDD-5195(0), ComM-CDD-5293(0), ComM-CDD-5094(0),
    ComM-CDD-5081(0), ComM-CDD-5172(0), ComM-CDD-5154(0), ComM-CDD-5188(0),
    ComM-CDD-5175(0), ComM-CDD-5261(0), ComM-CDD-5256(0), ComM-CDD-5287(0),
    ComM-CDD-5304(0) */
FUNC(void, COMM_CODE) ComM_Nm_NetworkMode(NetworkHandleType Channel)
{
    /*0x18*/
    Std_ReturnType  udtTReturn = E_OK;
    Std_ReturnType u8Return;
    boolean        bUserRequestActive;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_NETWORK_MODE_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (Channel >= ComM_u16NO_OF_CHANNELS)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_NETWORK_MODE_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        /*! Switch on sub-state */
        switch (ComM_au8StateMachines[Channel])
        {
        /*! in case COMM_SILENT_COM */
        case COMM_SILENT_COM:
            /*! set sub-state to u8TRANS_SILENT_TO_FULL */
            /*! set channel's value in ComM_au8WakeUpSleepStatus to
                u8ENTER_READY_SLEEP so that Nm_NetworkRelease() may be
                called if channel's ComMNmVariant is FULL */
            ComM_au8StateMachines[Channel] = u8TRANS_SILENT_TO_FULL;
            /*! Request COMM_FULL_COMMUNICATION from the channel's BusSM. */
            u8Return = ComM_pfu8RCOM_MODE(Channel, COMM_FULL_COMMUNICATION);
            ComM_au8WakeUpSleepStatus[Channel] = u8ENTER_READY_SLEEP;
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                       ComM_u8NM_NETWORK_MODE_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                ComM_au8StateMachines[Channel] = COMM_SILENT_COM;
            }
            break;
        /*! in case in a transient state to COMM_FULL_COMMUNICATION */
        case u8TRANS_NO_TO_FULL:
        case u8TRANS_SILENT_TO_FULL:
            /*! if channel's value in ComM_au8WakeUpSleepStatus is
                u8PASSIVE_WAKEUP and there is an active user request or an
                active diagnostic session:*/
            bUserRequestActive = ComM_bEvalChUserRequest(Channel);
            if (  (ComM_au8WakeUpSleepStatus[Channel] == u8PASSIVE_WAKEUP)
                &&(  (  (bUserRequestActive != FALSE)
                      #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                      &&(ComM_abeLimitToNoComStatus[Channel] == FALSE)
                      #endif /* ComM_bMODE_LIMIT_ENABLE */
                     )
                   #if (ComM_bCOMM_DCM_ENABLED == TRUE)
                   ||(ComM_abDCMActiveDiagnostic[Channel] != FALSE)
                   #endif /* ComM_bCOMM_DCM_ENABLED */
                  )
               )
            {
                /*! Call Nm_NetworkRequest(). */
                udtTReturn = Nm_NetworkRequest(Channel);
            }
            /*! If channel's value in ComM_au8WakeUpSleepStatus is \e NOT
                u8ENTER_READY_SLEEP switch to sub-state
                COMM_FULL_COM_NETWORK_REQUESTED and Notify users */
            if (ComM_au8WakeUpSleepStatus[Channel] != u8ENTER_READY_SLEEP)
            {
                ComM_au8StateMachines[Channel] =
                        COMM_FULL_COM_NETWORK_REQUESTED;
                if (udtTReturn == E_NOT_OK)
                {
                    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                       ComM_u8NM_NETWORK_MODE_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                    #endif /* ComM_bDEV_ERROR_DETECT */
                    ComM_au8WakeUpSleepStatus[Channel] = u8ACTIVE_WAKEUP;
                }
                else
                {
                    ComM_au8WakeUpSleepStatus[Channel] = u8NONE;
                }
                vidDoNotify(Channel, COMM_FULL_COMMUNICATION);
            }
            break;
        default:
            break;
        }
    }
}

/******************************************************************************/


/*! \Trace_To
    ComM-CDD-0165(0), ComM-CDD-0056(0), ComM-CDD-0059(0), ComM-CDD-5252(0),
    ComM-CDD-5227(0), ComM-CDD-5216(0), ComM-CDD-5142(0), ComM-CDD-5196(0),
    ComM-CDD-5288(0), ComM-CDD-5294(0), ComM-CDD-5303(0) */
FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode(NetworkHandleType Channel)
{
    /*0x19*/
    Std_ReturnType u8Return;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_PREPARE_BUS_SL_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (Channel >= ComM_u16NO_OF_CHANNELS)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_PREPARE_BUS_SL_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
    /*actual code here*/
        /*! If channel is in COMM_FULL_COMMUNICATION switch to
            u8TRANS_FULL_TO_SILENT and request COMM_SILENT_COMMUNICATION from
            the channel's BusSM. */
        if ((ComM_au8StateMachines[Channel] == COMM_FULL_COM_NETWORK_REQUESTED)
                ||(ComM_au8StateMachines[Channel] == COMM_FULL_COM_READY_SLEEP))
        {
            ComM_au8StateMachines[Channel] = u8TRANS_FULL_TO_SILENT;
            u8Return = ComM_pfu8RCOM_MODE(Channel, COMM_SILENT_COMMUNICATION);
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                     ComM_u8NM_PREPARE_BUS_SL_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                ComM_au8StateMachines[Channel] = COMM_SILENT_COM;
                ComM_au8WakeUpSleepStatus[Channel] = u8NONE;
                vidDoNotify(Channel, COMM_SILENT_COMMUNICATION);
            }
        }
    }
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0167(0), ComM-CDD-0041(0), ComM-CDD-0045(0), ComM-CDD-5228(0),
    ComM-CDD-5217(0), ComM-CDD-5060(0), ComM-CDD-5197(0), ComM-CDD-5250(0),
    ComM-CDD-5289(0), ComM-CDD-5143(0), ComM-CDD-5302(0) */
FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode(NetworkHandleType Channel)
{
    /*0x1A*/
    Std_ReturnType u8Return = E_OK;
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_BUS_SLEEP_MODE_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (Channel >= ComM_u16NO_OF_CHANNELS)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_BUS_SLEEP_MODE_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        /*! Switch on channel's sub-state */
        switch (ComM_au8StateMachines[Channel])
        {
        /*! in case COMM_SILENT_COM */
        case COMM_SILENT_COM:
            /*! switch to u8TRANS_SILENT_TO_NO */
            ComM_au8StateMachines[Channel] = u8TRANS_SILENT_TO_NO;
            /*! request COMM_NO_COMMUNICATION from the channel's BusSM. */
            u8Return = ComM_pfu8RCOM_MODE(Channel, COMM_NO_COMMUNICATION);
            break;
        /*! in case COMM_FULL_COM_NETWORK_REQUESTED or COMM_FULL_COM_READY_SLEEP
        */
        case COMM_FULL_COM_NETWORK_REQUESTED:
        case COMM_FULL_COM_READY_SLEEP:
            ComM_au8StateMachines[Channel] = u8TRANS_FULL_TO_NO;
            /*! request COMM_NO_COMMUNICATION from the channel's BusSM. */
            u8Return = ComM_pfu8RCOM_MODE(Channel, COMM_NO_COMMUNICATION);
            break;
        default:
            break;
        }
        if (u8Return != E_OK)
        {
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                 ComM_u8NM_BUS_SLEEP_MODE_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            #endif /* ComM_bDEV_ERROR_DETECT */
            ComM_au8StateMachines[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
            ComM_au8WakeUpSleepStatus[Channel] = u8ENTER_NO_COMM;
            vidDoNotify(Channel, COMM_NO_COMMUNICATION);
        }
    }
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0169(0), ComM-CDD-0034(0), ComM-CDD-5258(0), ComM-CDD-5144(0),
    ComM-CDD-5229(0), ComM-CDD-5218(0), ComM-CDD-5084(0), ComM-CDD-5198(0) */
FUNC(void, COMM_CODE) ComM_Nm_RestartIndication(NetworkHandleType Channel)
{
    /*0x1B*/
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_RESTART_INDICA_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (Channel >= ComM_u16NO_OF_CHANNELS)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8NM_RESTART_INDICA_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        /*! If channel is in sub-state COMM_NO_COM_NO_PENDING_REQUEST: */
        if (ComM_au8StateMachines[Channel] == COMM_NO_COM_NO_PENDING_REQUEST)
        {
            /*! set channel's value in ComM_au8WakeUpSleepStatus to
                u8PASSIVE_WAKEUP */
            ComM_au8WakeUpSleepStatus[Channel] = u8PASSIVE_WAKEUP;
            /*! Switch to COMM_NO_COM_REQUEST_PENDING */
            ComM_au8StateMachines[Channel] = COMM_NO_COM_REQUEST_PENDING;
        }
    }
}
#endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */
/******************************************************************************/

#if (ComM_bCOMM_DCM_ENABLED == TRUE)
/******************************************************************************/
/*                           DCM Indications Section                          */
/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0171(0), ComM-CDD-0063(0), ComM-CDD-0032(0), ComM-CDD-0040(0),
    ComM-CDD-5101(0), ComM-CDD-5180(0), ComM-CDD-5145(0), ComM-CDD-5230(0),
    ComM-CDD-5219(0), ComM-CDD-5295(0), ComM-CDD-5301(0) */
FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic(NetworkHandleType Channel)
{
    /*0x1F*/
    #if ((ComM_bANY_FULL_CHANNEL == TRUE) || (ComM_bANY_PASSIVE_CHANNEL))
    Std_ReturnType u8Return;
    uint8          u8TempWakeStatus;
    #endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8DCM_ACTIVE_DIAGNO_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (Channel >= ComM_u16NO_OF_CHANNELS)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8DCM_ACTIVE_DIAGNO_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        /*! Set channel's value in ComM_abDCMActiveDiagnostic to TRUE */
        ComM_abDCMActiveDiagnostic[Channel] = TRUE;
        /*! If channel is in sub-state COMM_NO_COM_NO_PENDING_REQUEST Switch to
            COMM_NO_COM_REQUEST_PENDING */
        if (ComM_au8StateMachines[Channel] == COMM_NO_COM_NO_PENDING_REQUEST)
        {
            ComM_au8StateMachines[Channel] = COMM_NO_COM_REQUEST_PENDING;
        }
        /*! else if channel is in sub-state COMM_FULL_COM_READY_SLEEP Switch to
            COMM_FULL_COM_NETWORK_REQUESTED and set channel's value in
            ComM_au8WakeUpSleepStatus to u8ACTIVE_WAKEUP  */
        else if (  (ComM_au8StateMachines[Channel] == COMM_FULL_COM_READY_SLEEP)
                 ||(ComM_au8StateMachines[Channel]
                                            == COMM_FULL_COM_NETWORK_REQUESTED))
        {
            ComM_au8WakeUpSleepStatus[Channel] = u8ACTIVE_WAKEUP;
            ComM_au8StateMachines[Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
        }
        /*! else if channel is in sub-state COMM_SILENT_COM:\n
            1- Switch to u8TRANS_SILENT_TO_FULL.\n
            2- set channel's value in ComM_au8WakeUpSleepStatus to
               u8ACTIVE_WAKEUP.\n
            3- Request COMM_FULL_COMMUNICATION from channel's BusSM. */
        #if ((ComM_bANY_FULL_CHANNEL == TRUE) || (ComM_bANY_PASSIVE_CHANNEL))
        else if (ComM_au8StateMachines[Channel] == COMM_SILENT_COM)
        {
            u8TempWakeStatus = ComM_au8WakeUpSleepStatus[Channel];
            ComM_au8StateMachines[Channel] = u8TRANS_SILENT_TO_FULL;
            ComM_au8WakeUpSleepStatus[Channel] = u8ACTIVE_WAKEUP;
            u8Return = ComM_pfu8RCOM_MODE(Channel, COMM_FULL_COMMUNICATION);
            if (u8Return != E_OK)
            {
                #if (ComM_bDEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                     ComM_u8DCM_ACTIVE_DIAGNO_ID, COMM_E_ERROR_IN_PROV_SERVICE);
                #endif /* ComM_bDEV_ERROR_DETECT */
                ComM_au8StateMachines[Channel] = COMM_SILENT_COM;
                ComM_au8WakeUpSleepStatus[Channel] = u8TempWakeStatus;
            }
        }
        else
        {
            /* Do Nothing */
        }
        #endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */
    }
}

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0172(0), ComM-CDD-5036(0), ComM-CDD-5146(0), ComM-CDD-5231(0),
    ComM-CDD-5220(0), ComM-CDD-5158(0), ComM-CDD-5199(0) */
FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic(NetworkHandleType Channel)
{
    /*0x20*/
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8DCM_INACTIVE_DIAG_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (Channel >= ComM_u16NO_OF_CHANNELS)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8DCM_INACTIVE_DIAG_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        /*! Set channel's value in ComM_abDCMActiveDiagnostic to FALSE */
        ComM_abDCMActiveDiagnostic[Channel] = FALSE;
    }
}

/******************************************************************************/
#endif /* ComM_bCOMM_DCM_ENABLED */

/******************************************************************************/
/*                        EcuM/BswM Indications Section                       */
/******************************************************************************/
/*! \Trace_To
    ComM-CDD-0173(0), ComM-CDD-0035(0), ComM-CDD-0033(0), ComM-CDD-5257(0),
    ComM-CDD-5147(0), ComM-CDD-5232(0), ComM-CDD-5082(0), ComM-CDD-5221(0),
    ComM-CDD-5190(0), ComM-CDD-5107(0), ComM-CDD-0265(0), ComM-CDD-0266(0) */
/* !Deviation: [3195] Parameter Always modified before being used only if
                      COMM_SYNCHRONOUS_WAKE_UP is set to true, because then
                      ALL channels should wake up not just the channel
                      indicated, and using a temporary variable just to fool
                      QA C does not make any sense */
/* PRQA S 3195 ++*/
FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication(NetworkHandleType Channel)
{
    /*0x2A*/
    /*! Reject Service if ComM is not initialised */
    #if (ComM_bSYNCHRONOUS_WAKE_UP == TRUE)
    #if (ComM_bPNC_SUPPORT == TRUE)
    uint8_least u8Idx;
    #endif /* ComM_bPNC_SUPPORT == TRUE */
    #endif /* ComM_bSYNCHRONOUS_WAKE_UP */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8ECU_M_WAKE_UP_IND_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (Channel >= ComM_u16NO_OF_CHANNELS)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8ECU_M_WAKE_UP_IND_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        /*! if configuration ComM_bSYNCHRONOUS_WAKE_UP is set to TRUE; enclose
            operations on passed channel in a for loop that loops on all
            channels */
        #if (ComM_bSYNCHRONOUS_WAKE_UP == TRUE)
        for (Channel=0; Channel<ComM_u16NO_OF_CHANNELS; Channel++)
        {
        #endif /* ComM_bSYNCHRONOUS_WAKE_UP */
            /*! if channel is in sub-state COMM_NO_COM_NO_PENDING_REQUEST set
                channel's value in ComM_au8WakeUpSleepStatus to u8PASSIVE_WAKEUP
                and switch it to COMM_NO_COM_REQUEST_PENDING. */
            if (ComM_au8StateMachines[Channel]
                                      == COMM_NO_COM_NO_PENDING_REQUEST)
            {
                ComM_au8WakeUpSleepStatus[Channel] = u8PASSIVE_WAKEUP;
                ComM_au8StateMachines[Channel] = COMM_NO_COM_REQUEST_PENDING;
            }
        #if (ComM_bSYNCHRONOUS_WAKE_UP == TRUE)
        }
        #if (ComM_bPNC_SUPPORT == TRUE)
        if (ComM_bePncEnabled !=FALSE)
        {
            for (u8Idx = 0; u8Idx < ComM_u8NO_OF_PNCS; u8Idx++)
            {
                if (ComM_au8PncState[u8Idx] == PNC_NO_COMMUNICATION)
                {
                    ComM_au8PncState[u8Idx] = PNC_PREPARE_SLEEP;
                    ComM_au16PncTimer[u8Idx] =
                                  ComM_aku16ePncTimerStart[u8Idx];
                    BswM_ComM_CurrentPNCMode(u8COMM_PNC_ID(u8Idx),
                                                             PNC_PREPARE_SLEEP);
                }
            }
        }
        #endif /* ComM_bPNC_SUPPORT */
        #endif /* ComM_bSYNCHRONOUS_WAKE_UP */
    }
}
/* PRQA S 3195 --*/

/******************************************************************************/

/*! \Trace_To
    ComM-CDD-0175(0), ComM-CDD-0017(0), ComM-CDD-5148(0), ComM-CDD-5243(0),
    ComM-CDD-5222(0), ComM-CDD-5085(0), ComM-CDD-5204(0) */
FUNC(void, COMM_CODE) ComM_CommunicationAllowed(NetworkHandleType Channel,
                                                boolean Allowed)
{
    /*0x35*/
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
#if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8COMMUNICATION_ALL_ID, COMM_E_NOT_INITED);
#endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if (  (Channel >= ComM_u16NO_OF_CHANNELS)
             #if (ComM_bDEV_ERROR_DETECT == STD_ON)
             ||((Allowed != TRUE) && (Allowed != FALSE))
             #endif /* ComM_bDEV_ERROR_DETECT */
            )
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8COMMUNICATION_ALL_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        /*! Set channel's value in ComM_abCommunicationAllowed to the passed
            value 'Allowed' */
        ComM_abCommunicationAllowed[Channel] = Allowed;
    }
}

/******************************************************************************/

/******************************************************************************/
/*                          BusSm Indications Section                         */
/******************************************************************************/
#if (ComM_bALL_INTERNAL == FALSE)
/*! \Trace_To
    ComM-CDD-0176(0), ComM-CDD-0178(0), ComM-CDD-5149(0), ComM-CDD-5233(0),
    ComM-CDD-5223(0), ComM-CDD-5156(0), ComM-CDD-5189(0), ComM-CDD-5184(0),
    ComM-CDD-5200(0), ComM-CDD-5155(0), ComM-CDD-5086(0), ComM-CDD-5161(0),
    ComM-CDD-5209(0), ComM-CDD-5117(0), ComM-CDD-5030(0), ComM-CDD-5291(0),
    ComM-CDD-5088(0), ComM-CDD-5276(0) */
/* !Deviation: [3673] Violates MISRA Rule 81: "contents of pointer are not
    modified and so so the pointer could be of type 'pointer to const'."
    This is true however the function prototype must stay the same as defined in
    AutOSAR's ComM SWS */
/* PRQA S 3673 ++*/
FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication(
                          NetworkHandleType Channel,
                          P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode)
{
    /*0x33*/
    /*! Reject Service if ComM is not initialised */
    ComM_ModeType  u8TempComMode;
    ComM_ModeType  u8FutureComMode;
    ComM_StateType u8CurState;
    #if (ComM_bDEV_ERROR_DETECT == STD_ON)
    Std_ReturnType u8Return;
    #endif /* ComM_bDEV_ERROR_DETECT */
    /*! if DET is enabled report un-initialised and parameter errors */
    if (ComM_udteInitStatus == COMM_UNINIT)
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8BUS_SM_MODE_INDIC_ID, COMM_E_NOT_INITED);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else if ((ComMode == NULL_PTR) ||
             (Channel >= ComM_u16NO_OF_CHANNELS) ||
               ((*ComMode != COMM_NO_COMMUNICATION) &&
                (*ComMode != COMM_FULL_COMMUNICATION) &&
                (*ComMode != COMM_SILENT_COMMUNICATION)))
    {
        #if (ComM_bDEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                ComM_u8BUS_SM_MODE_INDIC_ID, COMM_E_WRONG_PARAMETERS);
        #endif /* ComM_bDEV_ERROR_DETECT */
    }
    else
    {
        /*actual code here*/
        u8TempComMode = *ComMode;
        /*! Check that there is no conflict between indicated mode and current
            or requested ComMode, current or requested ComMode is retrieved from
            the return of u8GetChannelFutComMode() */
        u8FutureComMode = u8GetChannelFutComMode(Channel);
        if (u8TempComMode != u8FutureComMode)
        {
            /*! If there is a conflict, call BusSm_RequestComMode with the
                correct ComMode */
            /*! if DET is enabled report COMM_E_ERROR_IN_PROV_SERVICE if service
                returned with an error */
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            u8Return =
            #else
            (void)
            #endif /* ComM_bDEV_ERROR_DETECT */
            ComM_pfu8RCOM_MODE(Channel, u8FutureComMode);
            #if (ComM_bDEV_ERROR_DETECT == STD_ON)
            if (u8Return != E_OK)
            {
                (void)Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,
                     ComM_u8BUS_SM_MODE_INDIC_ID, COMM_E_ERROR_IN_PROV_SERVICE);
            }
            #endif /* ComM_bDEV_ERROR_DETECT */
        }
        else
        {
            /*! If there is no conflict, handle transient states */
            u8CurState = ComM_au8StateMachines[Channel];
            /*! if service was received in a transient state to
                COMM_NO_COMMUNICATION */
            if ((u8CurState == u8TRANS_FULL_TO_NO)
                        ||(u8CurState == u8TRANS_SILENT_TO_NO))
            {
                /*! Switch to COMM_NO_COM_NO_PENDING_REQUEST */
                ComM_au8StateMachines[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
                /*! raise u8ENTER_NO_COMM so that main may call
                    Nm_NetworkRelease() if required */
                ComM_au8WakeUpSleepStatus[Channel] = u8ENTER_NO_COMM;
                /*! Do Notifications */
                vidDoNotify(Channel,COMM_NO_COMMUNICATION);
            }
            /*! else if service was received in a transient state to
                COMM_FULL_COMMUNICATION */
            else if ((u8CurState == u8TRANS_NO_TO_FULL)
                             ||(u8CurState == u8TRANS_SILENT_TO_FULL))
            {
                #if (  (ComM_bANY_FULL_CHANNEL    == TRUE)\
                     ||(ComM_bANY_PASSIVE_CHANNEL == TRUE))
                /*! in case there is any FULL or PASSIVE Channels call
                    vidDoBusMITransToFull() */
                vidDoBusMITransToFull(Channel);
                #else /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */
                /*! otherwise switch to COMM_FULL_COM_NETWORK_REQUESTED */
                ComM_au8StateMachines[Channel] =
                                        COMM_FULL_COM_NETWORK_REQUESTED;
                /*! and Do Notifications */
                vidDoNotify(Channel, COMM_FULL_COMMUNICATION);
                #endif /* ComM_bANY_FULL_CHANNEL || ComM_bANY_PASSIVE_CHANNEL */
            }
            /*! else if service was received in a transient state to
                COMM_SILENT_COMMUNICATION */
            else if (u8CurState == u8TRANS_FULL_TO_SILENT)
            {
                /*! Switch to COMM_SILENT_COM */
                ComM_au8StateMachines[Channel] = COMM_SILENT_COM;
                /*! Do Notifications */
                vidDoNotify(Channel,COMM_SILENT_COMMUNICATION);
            }
            else
            {
                /*! else We're in the same mode as the indicated mode, that was
                    ensured by the conflict test, so Do Nothing */
            }
        }
    }
}
#endif /* ComM_bALL_INTERNAL */

/******************************************************************************/
/*                             PNC Supported Part                             */
/******************************************************************************/

#if (ComM_bPNC_SUPPORT == TRUE)

static FUNC(void, COMM_CODE) vidHandlePncState (const PNCHandleType ku8PncIdInd)
{
    uint16_least   u16Idx;
    PNCHandleType u8PncId =  u8COMM_PNC_ID(ku8PncIdInd);
    uint8 u8PncBit;
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    uint8 u8PncByte;
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
    uint8 u8ChId;
    /* Flag to test if there's a user request or not. */
    boolean bUsrReqExist = bEvalPncUserRequest(ku8PncIdInd);
    /* Flag to test if all channels of the PNC are in full Communication*/
    boolean bPncChFC = bCanPncNRRS(ku8PncIdInd);
    #if (ComM_bPNC_GW_ENABLED == TRUE)
    uint8 u8EraGwPncStatus;
    #endif /* ComM_bPNC_GW_ENABLED */

    /*!Locate the PNC bit in signal by PNC_ID % 8.*/
    u8PncBit = (u8PncId & ((uint8)0x07));
    if ((ComM_au8PncState[ku8PncIdInd] != PNC_REQUESTED))
    {
        if ((bUsrReqExist) && (bPncChFC))
        {
            /*!Change the PNC state to PNC_REQUESTED.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_REQUESTED;
            /*!Indicate the PNC state change to PNC_REQUESTED to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_REQUESTED);
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            /*!Locate the PNC Byte in signal by divide PNC_ID / 8.*/
            u8PncByte = (uint8)((u8PncId >> 3) + 
                                               (uint8)COMM_u8NEG_PN_VEC_OFFSET);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            /*!Set the PNC bit to 1.*/
            #if (ComM_bPNC_GW_ENABLED != TRUE)
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            ComM_au8T_SIG(ComM_au8eTxAgg, u8PncByte) |= (1 << u8PncBit);
            #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
            ComM_au8T_SIG(ComM_au8eTxAgg, 0) |= (1 << u8PncBit);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            #else /* ComM_bPNC_GW_ENABLED */
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            ComM_au8T_SIG(ComM_au8eTxERAAgg, u8PncByte) |= (1 << u8PncBit);
            #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
            ComM_au8T_SIG(ComM_au8eTxERAAgg, 0) |= (1 << u8PncBit);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            #endif /* ComM_bPNC_GW_ENABLED */
            /*!Send the User Status TX signal for the PNC with Com_SendSignal.*/
            #if (ComM_bPNC_GW_ENABLED == TRUE)
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd);
                                                                   u16Idx++)
            {
                (void)Com_SendSignal(
                            u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                              (void *)pu8ERA_GW_TX_AGG);
            }
            #else /* ComM_bPNC_GW_ENABLED */
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd);
                                                                       u16Idx++)
            {
                (void)Com_SendSignal(
                                u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                                      (void *)pu8TX_AGG);
            }
            #endif /* ComM_bPNC_GW_ENABLED */
            #if (ComM_bANY_PNC_NM_REQ == TRUE)
            for (u16Idx = 0; (u16Idx < u16PNC_CH_REF_SIZE(ku8PncIdInd))
                                                                     ; u16Idx++)
            {
                u8ChId = pu8PNC_CH_REF_ARRAY(ku8PncIdInd)[u16Idx];
                if ((ComM_au8StateMachines[u8ChId] ==
                                        COMM_FULL_COM_NETWORK_REQUESTED)
                 && (ComM_akbeNmPncRequest[u8ChId] == TRUE))
                {
                    ComM_au8WakeUpSleepStatus[u8ChId] = u8ACTIVE_WAKEUP;
                }
            }
            #endif /* COMM_bANY_PNC_NM_REQ == TRUE */
        }
    }
    /*If the PNC State is PNC_REQUESTED */
    else
    {
        #if (ComM_bPNC_GW_ENABLED == TRUE)
        SchM_Enter_ComM_AggEraGwSignal();
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        u8EraGwPncStatus = (ComM_au8T_SIG(ComM_au8eAggregERASig,u8PncByte) &
                                                               (1 << u8PncBit));
        #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
        u8EraGwPncStatus = (ComM_au8T_SIG(ComM_au8eAggregERASig, 0)
                                                             & (1 << u8PncBit));
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
        SchM_Exit_ComM_AggEraGwSignal();
        #endif /* ComM_bPNC_GW_ENABLED */
        if ((bUsrReqExist) && (FALSE == bPncChFC))
        {
            /*!Change the PNC state to PNC_READY_SLEEP.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_READY_SLEEP;
            /*!Indicate the PNC state change to PNC_READY_SLEEP to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_READY_SLEEP);
            /*!Set the PNC bit to 0.*/
            /*!Locate the PNC bit in signal by PNC_ID % 8.*/
            u8PncBit = (u8PncId & ((uint8)0x07));
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            /*!Locate the PNC Byte in signal by divide PNC_ID / 8.*/
            u8PncByte = (uint8)((u8PncId >> 3) + 
                                               (uint8)COMM_u8NEG_PN_VEC_OFFSET);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            #if (ComM_bPNC_GW_ENABLED == TRUE)
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            ComM_au8T_SIG(ComM_au8eTxERAAgg, u8PncByte) &= ~(1 << u8PncBit);
            #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
            ComM_au8T_SIG(ComM_au8eTxERAAgg, 0) &= ~(1 << u8PncBit);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            #else /* ComM_bPNC_GW_ENABLED */
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            ComM_au8T_SIG(ComM_au8eTxAgg, u8PncByte) &= ~(1 << u8PncBit);
            #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
            ComM_au8T_SIG(ComM_au8eTxAgg, 0) &= ~(1 << u8PncBit);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            #endif /* ComM_bPNC_GW_ENABLED */
            /*!Send the User Status TX signal for the PNC with Com_SendSignal.*/
            #if (ComM_bPNC_GW_ENABLED == TRUE)
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd);
                                                                       u16Idx++)
            {
                (void)Com_SendSignal(
                                u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                                  (void *)pu8ERA_GW_TX_AGG);
            }
            #else /* ComM_bPNC_GW_ENABLED */
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd);
                                                                       u16Idx++)
            {
                (void)Com_SendSignal(
                                u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                                      (void *)pu8TX_AGG);
            }
            #endif /* ComM_bPNC_GW_ENABLED */
        }
        /* No user request even if the channels are not in full communication.*/
        else if ((FALSE == bUsrReqExist)
                #if (ComM_bPNC_GW_ENABLED == TRUE)
                && (u8EraGwPncStatus == 0)
                #endif /* ComM_bPNC_GW_ENABLED */
                )
        {
            /*!Change the PNC state to PNC_READY_SLEEP.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_READY_SLEEP;
            /*!Indicate the PNC state change to PNC_READY_SLEEP to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_READY_SLEEP);
            /*!Set the PNC bit to 0.*/
            /*!Locate the PNC bit in signal by PNC_ID % 8.*/
            u8PncBit = (u8PncId & ((uint8)0x07));
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            /*!Locate the PNC Byte in signal by divide PNC_ID / 8.*/
            u8PncByte = (uint8)((u8PncId >> 3) + 
                                               (uint8)COMM_u8NEG_PN_VEC_OFFSET);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            #if (ComM_bPNC_GW_ENABLED == TRUE)
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            ComM_au8T_SIG(ComM_au8eTxERAAgg, u8PncByte) &= ~(1 << u8PncBit);
            #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
            ComM_au8T_SIG(ComM_au8eTxERAAgg, 0) &= ~(1 << u8PncBit);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            #else /* ComM_bPNC_GW_ENABLED */
            #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
            ComM_au8T_SIG(ComM_au8eTxAgg, u8PncByte) &= ~(1 << u8PncBit);
            #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
            ComM_au8T_SIG(ComM_au8eTxAgg, 0) &= ~(1 << u8PncBit);
            #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
            #endif /* ComM_bPNC_GW_ENABLED */
            /*!Send the User Status TX signal for the PNC with Com_SendSignal.*/
            #if (ComM_bPNC_GW_ENABLED == TRUE)
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd);
                                                                       u16Idx++)
            {
                (void)Com_SendSignal(
                                u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                                  (void *)pu8ERA_GW_TX_AGG);
            }
            #else /* ComM_bPNC_GW_ENABLED */
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd);
                                                                       u16Idx++)
            {
                (void)Com_SendSignal(
                                u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                                      (void *)pu8TX_AGG);
            }
            #endif /* ComM_bPNC_GW_ENABLED */
        }else
        {
          /* Do Nothing */
        }
    }
}

static FUNC(boolean, COMM_CODE) bEvalPncUserRequest(
                                                const PNCHandleType ku8PncIdInd)
{
    uint8_least   u8Idx;
    boolean bActiveRequest = FALSE;
    for (u8Idx = 0; ((u8Idx < u8PNC_USR_REF_SIZE(ku8PncIdInd)) &&
                     (bActiveRequest == FALSE)); u8Idx++)
    {
        bActiveRequest =
             ComM_abUserRequestStatus[pu8PNC_USR_REF_ARRAY(ku8PncIdInd)[u8Idx]];
    }
    return bActiveRequest;
}

static FUNC(boolean, COMM_CODE) bCanPncNRRS(const PNCHandleType ku8PncIdInd)
{
    uint16_least   u16Idx;
    boolean bCanPncNRRSFlag = TRUE;
    for (u16Idx = 0; ((u16Idx < u16PNC_CH_REF_SIZE(ku8PncIdInd)) &&
                                      (bCanPncNRRSFlag == TRUE)); u16Idx++)
    {
        if ((ComM_au8StateMachines[pu8PNC_CH_REF_ARRAY(ku8PncIdInd)[u16Idx]] !=
                                COMM_FULL_COM_NETWORK_REQUESTED)
         && (ComM_au8StateMachines[pu8PNC_CH_REF_ARRAY(ku8PncIdInd)[u16Idx]] !=
                                COMM_FULL_COM_READY_SLEEP))
        {
            bCanPncNRRSFlag = FALSE;
        }
    }
    return bCanPncNRRSFlag;
}

FUNC(void, COMM_CODE) ComM_vidEraEiraHEvaluate(
                                             const NetworkHandleType ku8Channel
                                             #if (ComM_bPNC_GW_ENABLED == TRUE)
                                           , const boolean kbActGWCh
                                           #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                           , const boolean kbLimToNoCom
                                           #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                           , const boolean kbNoWakeUp
                                           #endif /* ComM_bWAKEUP_INH_ENABLE */
                                           #endif /* ComM_bMODE_LIMIT_ENABLE */
                                           #endif /* ComM_bPNC_GW_ENABLED */
                                             )
{
    uint8_least u8Idx;
    #if (ComM_bPNC_GW_ENABLED == TRUE)
    for (u8Idx = 0 ; u8Idx < u8CH_ERAPNC_REF_SIZE(ku8Channel) ; u8Idx++)
    {
        vidEraGwHandle(ku8Channel, kbActGWCh
                                    , u8CH_ERAPNC_REF_ARRAY(ku8Channel)[u8Idx]
                                    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                    , kbLimToNoCom
                                    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                    , kbNoWakeUp
                                    #endif /* ComM_bWAKEUP_INH_ENABLE */
                                    #endif /* ComM_bMODE_LIMIT_ENABLE */
                                           );
    }
    #endif /* ComM_bPNC_GW_ENABLED */

    for (u8Idx = 0 ; u8Idx < u8CH_PNC_REF_SIZE(ku8Channel) ; u8Idx++)
    {
        vidEiraHandle(ku8Channel,
                      (bIsCountPncTimer(u8CH_PNC_REF_ARRAY(ku8Channel)[u8Idx]
                                                                 , ku8Channel)),
                                       (u8CH_PNC_REF_ARRAY(ku8Channel)[u8Idx]));
    }
}

static void vidEiraHandle(const NetworkHandleType ku8Channel,
                          const boolean kbEvalPS,
                          const PNCHandleType ku8PncIdInd)
{
    uint8 u8EiraPncStatus;
    uint8 u8PncBit;
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    uint8 u8PncByte;
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
    PNCHandleType u8PncId =  u8COMM_PNC_ID(ku8PncIdInd);
    /*!Locate the PNC bit in signal by PNC_ID % 8.*/
    u8PncBit = (u8PncId & ((uint8)0x07));
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    /*!Locate the PNC Byte in signal by divide PNC_ID / 8.*/
    u8PncByte = (uint8)((u8PncId >> 3) + (uint8)COMM_u8NEG_PN_VEC_OFFSET);
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */

    SchM_Enter_ComM_AggregatedSignal();
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    u8EiraPncStatus = (ComM_au8T_SIG(ComM_au8eAggregSignal, u8PncByte) &
                                                               (1 << u8PncBit));
    #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
    u8EiraPncStatus = (ComM_au8T_SIG(ComM_au8eAggregSignal, 0)
                                                             & (1 << u8PncBit));
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
    SchM_Exit_ComM_AggregatedSignal();
    if ((u8EiraPncStatus > 0)
                    && (ComM_au8PncState[ku8PncIdInd] != PNC_REQUESTED))
    {
        /*!Test if all the channels mapped to the PNC are in full
           communication*/
        if((bCanPncNRRS(ku8PncIdInd))
                         && (ComM_au8PncState[ku8PncIdInd] != PNC_READY_SLEEP))
        {
            /*!Change the PNC state to PNC_READY_SLEEP.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_READY_SLEEP;
            /*!Indicate the PNC state change to PNC_READY_SLEEP to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_READY_SLEEP);
        }
        else if((FALSE == bCanPncNRRS(ku8PncIdInd))
                         && (ComM_au8PncState[ku8PncIdInd] == PNC_READY_SLEEP))
        {
            /*!Change the PNC state to PNC_PREPARE_SLEEP.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_PREPARE_SLEEP;
            /*!Start the PNC prepare sleep timer of the PNC.*/
            ComM_au16PncTimer[ku8PncIdInd] =
                                       ComM_aku16ePncTimerStart[ku8PncIdInd];
            /*!Indicate the PNC state change to PNC_PREPARE_SLEEP to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_PREPARE_SLEEP);
        }
        /*!If not all channels are in full communication all the channels'
        ComM_au8WakeUpSleepStatus will be updated with u8PASSIVE_WAKEUP. */
        else
        {
            if (ComM_au8StateMachines[ku8Channel] ==
                                             COMM_NO_COM_NO_PENDING_REQUEST)
            {
                ComM_au8StateMachines[ku8Channel] =
                                                COMM_NO_COM_REQUEST_PENDING;
                ComM_au8WakeUpSleepStatus[ku8Channel] = u8PASSIVE_WAKEUP;
            }
            else if (ComM_au8StateMachines[ku8Channel] ==
                                                    COMM_NO_COM_REQUEST_PENDING)
            {
                ComM_au8WakeUpSleepStatus[ku8Channel] = u8PASSIVE_WAKEUP;
            }
            else if (ComM_au8StateMachines[ku8Channel] == COMM_SILENT_COM)
            {
                vidGoToFCom(ku8Channel);
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else if (((u8EiraPncStatus == 0)
                        && (ComM_au8PncState[ku8PncIdInd] == PNC_READY_SLEEP)))
    {
            /*!Change the PNC state to PNC_PREPARE_SLEEP.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_PREPARE_SLEEP;
            /*!Start the PNC prepare sleep timer of the PNC.*/
            ComM_au16PncTimer[ku8PncIdInd] =
                                        ComM_aku16ePncTimerStart[ku8PncIdInd];
            /*!Indicate the PNC state change to PNC_PREPARE_SLEEP to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_PREPARE_SLEEP);
    }
  else
  {
    /* Do nothing */
  }

    /*! Handle transition the state of PNC_PREPARE_SLEEP.*/
    if ((kbEvalPS) && (ComM_au8PncState[ku8PncIdInd] == PNC_PREPARE_SLEEP))
    {
        if (!(ComM_au16PncTimer[ku8PncIdInd]))
        {
            /*!Change the PNC state to PNC_READY_SLEEP.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_NO_COMMUNICATION;
            /*!Indicate the PNC state change to PNC_NO_COMMUNICATION to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_NO_COMMUNICATION);
        }
        else
        {
            ComM_au16PncTimer[ku8PncIdInd]--;
        }
    }
}

static FUNC(boolean, COMM_CODE) bIsCountPncTimer(
                                             const PNCHandleType ku8PncIdInd,
                                             const NetworkHandleType ku8Channel)
{
    boolean bReturn = FALSE;
    if (ComM_aku8ePncTimerChannels[ku8PncIdInd] == ku8Channel)
    {
        bReturn = TRUE;
    }
    return bReturn;
}

#if (ComM_bPNC_GW_ENABLED == TRUE)
static void vidEraGwHandle(
                            const NetworkHandleType ku8Channel,
                            const boolean kbActGWCh,
                            const PNCHandleType ku8PncIdInd
                            #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                            , const boolean kbLimToNoCom
                            #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                            , const boolean kbNoWakeUp
                            #endif /* ComM_bWAKEUP_INH_ENABLE */
                            #endif /* ComM_bMODE_LIMIT_ENABLE */
                            )
{
    uint16_least   u16Idx;
    PNCHandleType u8PncId =  u8COMM_PNC_ID(ku8PncIdInd);
    uint8 u8EraGwPncStatus;
    uint8 u8PncBit;
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    uint8 u8PncByte;
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
    uint8 u8ChId;
    /* Flag to test if there's a user request or not. */
    boolean bUsrReqExist = bEvalPncUserRequest(ku8PncIdInd);
    /* Flag to test if all channels of the PNC are in full Communication*/
    boolean bPncChFC = bCanPncNRRS(ku8PncIdInd);
    boolean bGwPncChNR = bCanPncGwNR(ku8PncIdInd);
    /*!Locate the PNC bit in signal by PNC_ID % 8.*/
    u8PncBit = (u8PncId & ((uint8)0x07));
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    /*!Locate the PNC Byte in signal by divide PNC_ID / 8.*/
    u8PncByte = (uint8)((u8PncId >> 3) + (uint8)COMM_u8NEG_PN_VEC_OFFSET);
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    u8EraGwPncStatus = (ComM_au8T_SIG(ComM_au8eAggregERASig,u8PncByte) &
                                                               (1 << u8PncBit));
    #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
    u8EraGwPncStatus = (ComM_au8T_SIG(ComM_au8eAggregERASig, 0)
                                                              & (1 << u8PncBit));
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
    if(u8EraGwPncStatus > 0)
    {
        ComM_abChGwPncReq[ku8Channel] = TRUE;
    }
    else
    {
        ComM_abChGwPncReq[ku8Channel] = bIsGwChReq(ku8Channel);
    }
    if (ComM_au8PncState[ku8PncIdInd] == PNC_REQUESTED)
    {
        if ((u8EraGwPncStatus == 0) && (FALSE == bUsrReqExist))
        {
            /*!Change the PNC state to PNC_READY_SLEEP.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_READY_SLEEP;
            /*!Indicate the PNC state change to PNC_READY_SLEEP to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_READY_SLEEP);
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd);
                                                                       u16Idx++)
            {
                (void)Com_SendSignal(
                                u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                                  (void *)pu8ERA_GW_TX_AGG);
            }
        }
        else if (FALSE == bPncChFC)
        {
            /*!Change the PNC state to PNC_READY_SLEEP.*/
            ComM_au8PncState[ku8PncIdInd] = PNC_READY_SLEEP;
            /*!Indicate the PNC state change to PNC_READY_SLEEP to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_READY_SLEEP);
            ComM_au8T_SIG(ComM_au8eTxERAAgg,u8PncByte) &=  ~(1 << u8PncBit);
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd);
                                                                       u16Idx++)
            {
                (void)Com_SendSignal(
                                u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                                  (void *)pu8ERA_GW_TX_AGG);
            }
        }
    else
        {
          /* Do nothing */
        }
    }
    else if ((ComM_au8PncState[ku8PncIdInd] != PNC_REQUESTED)
                && (u8EraGwPncStatus > 0)
                && (FALSE != kbActGWCh))
    {
        if ((bGwPncChNR) 
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        && (FALSE == kbLimToNoCom)
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        )
        {
            ComM_au8PncState[ku8PncIdInd] = PNC_REQUESTED;
            /*!Indicate the PNC state change to PNC_REQUESTED to BswM.*/
            BswM_ComM_CurrentPNCMode(u8PncId, PNC_REQUESTED);
            for (u16Idx =0 ; u16Idx < u16PNC_TX_SIG_REF_SIZE(ku8PncIdInd)
                                                                     ; u16Idx++)
            {
                (void)Com_SendSignal(
                                u16PNC_TX_SIG_REF_ARRAY(ku8PncIdInd)[u16Idx],
                                                  (void *)pu8ERA_GW_TX_AGG);
            }
            #if (ComM_bANY_PNC_NM_REQ == TRUE)
            for (u16Idx = 0; (u16Idx < u16PNC_CH_REF_SIZE(ku8PncIdInd))
                                                                     ; u16Idx++)
            {
                u8ChId = pu8PNC_CH_REF_ARRAY(ku8PncIdInd)[u16Idx];
                if (ComM_akbeNmPncRequest[u8ChId] ==  TRUE)
                {
                    ComM_au8WakeUpSleepStatus[u8ChId] = u8ACTIVE_WAKEUP;
                }
            }
            #endif /* COMM_bANY_PNC_NM_REQ == TRUE */
        }
        else
        {
            #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
            if((FALSE == kbLimToNoCom)
            #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                && (FALSE == kbNoWakeUp)
            #endif /* ComM_bWAKEUP_INH_ENABLE */
            )
            {
            #endif /* ComM_bMODE_LIMIT_ENABLE */
                if (ComM_au8StateMachines[ku8Channel] ==
                                                 COMM_NO_COM_NO_PENDING_REQUEST)
                {
                    ComM_au8StateMachines[ku8Channel] =
                                                    COMM_NO_COM_REQUEST_PENDING;
                    ComM_au8WakeUpSleepStatus[ku8Channel] = u8ACTIVE_WAKEUP;
                }
                else if (ComM_au8StateMachines[ku8Channel] ==
                                                    COMM_NO_COM_REQUEST_PENDING)
                {
                    ComM_au8WakeUpSleepStatus[ku8Channel] = u8ACTIVE_WAKEUP;
                }
                else if (ComM_au8StateMachines[ku8Channel] == COMM_SILENT_COM)
                {
                    vidGoToFCom(ku8Channel);
                }else
                {
                  /* Do nothing */
                }
            #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
            }else if (FALSE == kbLimToNoCom)
            {
            #endif /* ComM_bMODE_LIMIT_ENABLE */
                if (ComM_au8StateMachines[ku8Channel] ==
                                                      COMM_FULL_COM_READY_SLEEP)
                {
                    ComM_au8StateMachines[ku8Channel] =
                                                COMM_FULL_COM_NETWORK_REQUESTED;
                    ComM_au8WakeUpSleepStatus[ku8Channel] = u8ACTIVE_WAKEUP;
                }else if (ComM_au8StateMachines[ku8Channel] ==
                                                COMM_FULL_COM_NETWORK_REQUESTED)
                {
                    ComM_au8WakeUpSleepStatus[ku8Channel] = u8NONE;
                }else
                {
                  /* Do nothing */
                }
            #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
            }else
            {
                /* Do nothing */
            }
            #endif /* ComM_bMODE_LIMIT_ENABLE */
        }
    }
    else
    {
      /* Do nothing */
    }
}

static FUNC(boolean, COMM_CODE) bCanPncGwNR(const PNCHandleType ku8PncIdInd)
{
    uint16_least   u16Idx;
    boolean bCanPncGwNRFlag = TRUE;
    for (u16Idx = 0; ((u16Idx < u16PNC_CH_REF_SIZE(ku8PncIdInd)) &&
                                      (bCanPncGwNRFlag == TRUE)); u16Idx++)
    {
        if (ComM_au8StateMachines[pu8PNC_CH_REF_ARRAY(ku8PncIdInd)[u16Idx]] !=
                                COMM_FULL_COM_NETWORK_REQUESTED)
        {
            bCanPncGwNRFlag = FALSE;
        }
    }
    return bCanPncGwNRFlag;
}


static FUNC(boolean, COMM_CODE) bIsGwChReq(const NetworkHandleType ku8Channel)
{
    uint8_least   u8Idx;
    uint8 u8EraGwPncStatus;
    uint8 u8PncId;
    boolean bIsGwChReqFlag = FALSE;
    uint8 u8PncBit;
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    uint8 u8PncByte;
    #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
    for (u8Idx = 0; ((u8Idx < u8CH_ERAPNC_REF_SIZE(ku8Channel)) 
                                         && (bIsGwChReqFlag == FALSE)); u8Idx++)
    {
        u8PncId = u8COMM_PNC_ID(u8CH_ERAPNC_REF_ARRAY(ku8Channel)[u8Idx]);
        u8PncBit = (u8PncId & ((uint8)0x07));
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        u8PncByte = (uint8)((u8PncId >> 3) + (uint8)COMM_u8NEG_PN_VEC_OFFSET);
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        u8EraGwPncStatus = (ComM_au8T_SIG(ComM_au8eAggregERASig,u8PncByte) &
                                                               (1 << u8PncBit));
        #elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
        u8EraGwPncStatus = (ComM_au8T_SIG(ComM_au8eAggregERASig, 0)
                                                             & (1 << u8PncBit));
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
        if (u8EraGwPncStatus > 0)
        {
            bIsGwChReqFlag = TRUE;
        }
    }
    return bIsGwChReqFlag;
}

#endif /* ComM_bPNC_GW_ENABLED */
#endif /* ComM_bPNC_SUPPORT */

/******************************************************************************/




/* PRQA S 3673 --*/
#define COMM_STOP_SEC_CODE
/* PRQA S 838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */


/* PRQA S 0857 -- */
/* PRQA S 0850 --                                                             */
/******************************************************************************/

/** \} */ /* end of ComM module group */



