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
/* !File            : ComM_Internal.h                                         */
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
/* $Revision::   1.27     $$Author::   knasr          $$Date::   Jun 27 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/******************************************************************************/
/* @DESIGN MODIFICATION LOG :                                                 */
/******************************************************************************/
/* @Modified by     :                                      @Date :            */
/*                                                                            */
/* @TFR             :                                                         */
/*                                                                            */
/* Version :                                                                  */
/*    @Issued on    :                                                         */
/*    @Corrected in :                                                         */
/*                                                                            */
/* @Description     :                                                         */
/******************************************************************************/
/* @CODE MODIFICATION LOG :                                                   */
/******************************************************************************/
/* @Modified by     :                                      @Date :            */
/*                                                                            */
/* @TFR             :                                                         */
/*                                                                            */
/* Version :                                                                  */
/*    @Issued on    :                                                         */
/*    @Corrected in :                                                         */
/*                                                                            */
/* @Description     :                                                         */
/******************************************************************************/

/******************************************************************************/
/*! \file ComM_Internal.h
*
* \par
*   Internal Declarations of cross-module functions of the module ComM.       */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module ComM
* This is the grouping of the ComM module members.
* \{
*/
#ifndef COMM_INTERNAL_H

/* !Deviation: [0857] Under certain configurations, ComM may have more than
    1024 definitions, so the compiler should be able to handle more than 1024
    definitions. */

/* PRQA S 0857 ++ */
/* !Deviation: [3453] Violates MISRA rule 93: "A function should be used in
    preference to a function-like macro." but these function-like macros are
    only to abbreviate long function calls to make the code more readable and to
    avoid breaking the 80 characters mark.
*/
/* PRQA S 3453 ++ */
#define COMM_INTERNAL_H



#if (ComM_bPNC_SUPPORT == TRUE)

#include "Com.h"


#if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)

#define ComM_au8T_SIG(SIG, ID) ((SIG)[ID])
/* PRQA S 3453 -- */
#elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)
#define ComM_au8eAggregSignal                   ComM_u8eAggregSignal
#define ComM_au8eTxAgg                          ComM_u8TxAgg
#if (ComM_bPNC_GW_ENABLED == TRUE)
#define ComM_au8eAggregERASig                   ComM_u8eAggregERASig
#define ComM_au8eTxERAAgg                       ComM_u8eTxERAAgg
#endif /* ComM_bPNC_GW_ENABLED */

/* PRQA S 3453 ++*/
#define ComM_au8T_SIG(SIG, ID) (SIG)
/* PRQA S 3453 --*/

#endif /* ComM_u8NO_SIZE_OF_SIG_ARR */

#endif /* ComM_bPNC_SUPPORT */


#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
typedef struct
{
    boolean bComMNoCom;
    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
    boolean bComMNoWakeup;
    #endif /* ComM_bWAKEUP_INH_ENABLE */
} ComM_tstrInhibitionConfig;
#endif /* ComM_bMODE_LIMIT_ENABLE */


typedef struct
{
    const uint16 ComM_ku16Size;
    const NetworkHandleType* const ComM_kpku8ChannelsArray;
} ComM_tudtChannelsPerUserType;


typedef struct
{
    const uint8 ComM_ku8Size;
    const ComM_UserHandleType* const ComM_kpku8UsersArray;
} ComM_tudtUsersPerChannelType;

#if (ComM_bPNC_SUPPORT == TRUE)
typedef struct
{
    const uint8 ComM_ku8Size;
    const PNCHandleType* const ComM_kpku8PncsArray;
} ComM_tudtPncsPerChannelType;


typedef struct
{
    const uint8 ComM_ku8Size;
    const NetworkHandleType* const ComM_kpku8ChannelsArray;
} ComM_tudtChannelsPerPncType;


typedef struct
{
    const uint8 ComM_ku8Size;
    const ComM_UserHandleType* const ComM_kpku8UsersArray;
} ComM_tudtUsersPerPncType;


typedef struct
{
    const uint16 ComM_ku16Size;
    const Com_SignalIdType* const ComM_kpku16SigsArray;
} ComM_tudtTxSigPerPncType;

#if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)

typedef uint8 ComM_au8SignalArrayType[ComM_u8NO_SIZE_OF_SIG_ARR];

#elif (ComM_u8NO_SIZE_OF_SIG_ARR == 1)

typedef uint8 ComM_au8SignalArrayType;

#endif

#endif /* ComM_bPNC_SUPPORT */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
#if (ComM_bRTE_USED == STD_ON)
typedef P2FUNC(Std_ReturnType, TYPEDEF, ComM_tpfu8ModeMSI)
                                                (Rte_ModeType_ComMMode ComMode);
#elif (ComM_bRTE_USED == STD_OFF)
typedef P2FUNC(Std_ReturnType, TYPEDEF, ComM_tpfu8ModeMSI)
                                                (User_ModeType_ComMMode ComMode); 
#endif /* ComM_bRTE_USED */                                                
/* PRQA S 0850 --                                                             */

#if (ComM_bMULTI_BUS_MODE == TRUE)
typedef P2FUNC(Std_ReturnType, TYPEDEF, ComM_tpfu8RequestComMode)
                                (NetworkHandleType network, ComM_ModeType mode);
typedef P2FUNC(Std_ReturnType, TYPEDEF, ComM_tpfu8GetCurrentComMode)
                           (NetworkHandleType network,
                            P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) mode);
#endif /* ComM_bMULTI_BUS_MODE */

#define COMM_START_SEC_VAR_8
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern VAR(ComM_InitStatusType, COMM_VAR_POWER_ON_INIT) ComM_udteInitStatus;
#if (ComM_bPNC_SUPPORT == TRUE)
extern VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_au8eAggregSignal;
/* PRQA S 0850 --                                                             */
#if (ComM_bPNC_GW_ENABLED == FALSE)
extern VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_au8eTxAgg;
#endif /* ComM_bPNC_GW_ENABLED */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
#if (ComM_bPNC_GW_ENABLED == TRUE)
extern VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_au8eAggregERASig;

extern VAR(ComM_au8SignalArrayType, COMM_VAR) ComM_au8eTxERAAgg;
/* PRQA S 0850 --                                                             */
#endif /* ComM_bPNC_GW_ENABLED */
#endif /* ComM_bPNC_SUPPORT */
#define COMM_STOP_SEC_VAR_8
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/


#define COMM_START_CONFIG_DATA_UNSPECIFIED
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern CONST(ComM_tudtUsersPerChannelType, COMM_CFG_CONST)
                            ComM_akudteUsersPerChannel[ComM_u16NO_OF_CHANNELS];


extern CONST(ComM_tudtChannelsPerUserType, COMM_CFG_CONST)
                                 ComM_akudteChannelsPerUser[ComM_u8NO_OF_USERS];
extern CONST(ComM_tpfu8ModeMSI, COMM_CFG_CONST)
                              ComM_akpfu8eUserModeMSIArray[ComM_u8NO_OF_USERS];
/* PRQA S 0850 --                                                             */

#if (ComM_bMULTI_BUS_MODE == TRUE)
extern CONST(ComM_tpfu8RequestComMode, COMM_CFG_CONST)
                        ComM_akpfu8eRequestComModeArray[ComM_u16NO_OF_CHANNELS];


extern CONST(ComM_tpfu8GetCurrentComMode, COMM_CFG_CONST)
                           ComM_akpfu8eGCurComModeArray[ComM_u16NO_OF_CHANNELS];

#endif /*ComM_bMULTI_BUS_MODE */

#if (ComM_bPNC_SUPPORT == TRUE)

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern CONST(PNCHandleType, COMM_CFG_CONST) ComM_aku8ePncId[ComM_u8NO_OF_PNCS];

extern CONST(NetworkHandleType, COMM_CFG_CONST)
                                   ComM_akbeNmPncRequest[ComM_u16NO_OF_CHANNELS];

extern CONST(ComM_tudtChannelsPerPncType, COMM_CFG_CONST)
                                   ComM_akudteChannelsPerPnc[ComM_u8NO_OF_PNCS];


extern CONST(ComM_tudtPncsPerChannelType, COMM_CFG_CONST)
                             ComM_akudtePncsPerChannel[ComM_u16NO_OF_CHANNELS];


extern CONST(ComM_tudtUsersPerPncType, COMM_CFG_CONST)
                                      ComM_akudteUsersPerPnc[ComM_u8NO_OF_PNCS];


extern CONST(uint16, COMM_CFG_CONST) ComM_aku16ePncTimerStart[ComM_u8NO_OF_PNCS];

extern CONST(Com_SignalIdType, COMM_CFG_CONST)
                                ComM_aku16eEiraRxSig[ComM_u16NO_OF_RX_EIRA_SIG];

extern CONST(ComM_tudtTxSigPerPncType, COMM_CFG_CONST)
                                  ComM_akudteTxSignalsPerPnc[ComM_u8NO_OF_PNCS];

extern CONST(uint8, COMM_CFG_CONST)
                                  ComM_aku8ePncTimerChannels[ComM_u8NO_OF_PNCS];

#if (ComM_bPNC_GW_ENABLED == TRUE)

extern CONST(Com_SignalIdType, COMM_CFG_CONST)
                             ComM_aku16eEraGwRxSig[ComM_u16NO_OF_RX_GWERA_SIG];
extern CONST(ComM_tudtPncsPerChannelType, COMM_CFG_CONST)
                             ComM_akudteEraPncsPerCh[ComM_u16NO_OF_CHANNELS];
#endif /*ComM_bPNC_GW_ENABLED */
#endif /* ComM_bPNC_SUPPORT */

#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
extern CONST(ComM_tstrInhibitionConfig, COMM_CFG_CONST)
            ComM_akstreInhibitionConfig[ComM_u16NO_OF_CHANNELS];
#endif /* ComM_bMODE_LIMIT_ENABLE */
/* PRQA S 0850 --                                                             */

#define COMM_STOP_CONFIG_DATA_UNSPECIFIED
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/


#define COMM_START_SEC_VAR_UNSPECIFIED
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern VAR(ComM_InhibitionStatusType, COMM_VAR)
        ComM_u8eECUGClassification;
extern VAR(boolean, COMM_VAR)
        ComM_abeLimitToNoComStatus[ComM_u16NO_OF_CHANNELS];
extern VAR(boolean, COMM_VAR)
        ComM_abeWakeUpInibitStatus[ComM_u16NO_OF_CHANNELS];
#if ComM_bANY_FCOM_SRI_ENABLE
extern VAR(boolean, COMM_VAR)
        ComM_abeChannelReqsUpdated[ComM_u16NO_OF_CHANNELS];
#endif /* ComM_bANY_FCOM_SRI_ENABLE */

#if (ComM_bPNC_SUPPORT == TRUE)

extern VAR(boolean, COMM_VAR) ComM_bePncEnabled;
/* PRQA S 0850 --                                                             */

#endif /* ComM_bPNC_SUPPORT */
#define COMM_STOP_SEC_VAR_UNSPECIFIED
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

#define COMM_START_SEC_CODE
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

#if (ComM_bANY_PASSIVE_CHANNEL == TRUE)
/******************************************************************************/
/*! \Description Function to manage the state machine of ComMNmVariant=PASSIVE
                 channels.
    \param[in]  ku8Channel The Channel to be managed.                         \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_vidManagePASSIVESM(
                             const NetworkHandleType ku8Channel);
#endif /* ComM_bANY_PASSIVE_CHANNEL */

#if (ComM_bANY_FULL_CHANNEL == TRUE)
/******************************************************************************/
/*! \Description Function to manage the state machine of ComMNmVariant=FULL
                 channels.
    \param[in]  ku8Channel The Channel to be managed.                         \n
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
extern FUNC(void, COMM_CODE) ComM_vidManageFULLSM(
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

/* PRQA S 0850 --                                                             */


#if (ComM_bANY_LIGHT_CHANNEL == TRUE)
/******************************************************************************/
/*! \Description Function to manage the state machine of ComMNmVariant=LIGHT
                 channels.
    \param[in]  ku8Channel The Channel to be managed.                         \n
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
    \param[in,out]  kpu32Cycles Pointer to the channel's main function
                    timer-counter.                                            \n
                    \Unit Pointer to uint32
    \param[in]  ku32LightTOut ComMNmVariant LIGHT timeout counts.             \n
                \Unit uint32
    \param[in]  ku32MinFULLDur Minimum Full Communication main function counts.
                \n
                \Unit uint32
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_vidManageLIGHTSM(
                             const NetworkHandleType ku8Channel,
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
                             const uint32 ku32LightTOut);
#endif /* ComM_bANY_LIGHT_CHANNEL */

#if (ComM_bANY_INTERNAL_CHANNEL == TRUE)
/******************************************************************************/
/*! \Description Function to manage the state machine of ComMNmVariant=NONE
                 channels whose bus type \e is INTERNAL.
    \param[in]  ku8Channel The Channel to be managed.                         \n
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
    \param[in,out]  kpu32Cycles Pointer to the channel's main function
                    timer-counter.                                            \n
                    \Unit Pointer to uint32
    \param[in]  ku32MinFULLDur Minimum Full Communication main function counts.
                \n
                \Unit uint32
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_vidManInternalNONESM(
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
                             );
#endif /* ComM_bANY_INTERNAL_CHANNEL */

#if (ComM_bANY_NI_NONE == TRUE)
/******************************************************************************/
/*! \Description Function to manage the state machine of ComMNmVariant=NONE
                 channels whose bus type is \e not INTERNAL.
    \param[in]  ku8Channel The Channel to be managed.                         \n
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
    \param[in,out]  kpu32Cycles Pointer to the channel's main function
                    timer-counter.                                            \n
                    \Unit Pointer to uint32
    \param[in]  ku32MinFULLDur Minimum Full Communication main function counts.
                \n
                \Unit uint32
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_vidManNotInternalNONESM(
                             const NetworkHandleType ku8Channel,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             const boolean  kbLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             const boolean  kbActiveUR,
                             uint32 * const kpu32Cycles,
                             const uint32  ku32MinFULLDur
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , const boolean  kbNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             );
#endif /* ComM_bANY_NI_NONE */


/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description Function to get, for a channel, the status of its users'
                 requests, returns TRUE if there is an active user request,
                 FALSE otherwise.                                             \n
                 It must be noted that this function does not take into account
                 the mode inhibition status.
    \param[in]  ku8Channel The Channel for which the users' requests status will
                be retrieved.                                                 \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \return     TRUE, FALSE.
*******************************************************************************/
extern FUNC(boolean, COMM_CODE)
        ComM_bEvalChUserRequest(const NetworkHandleType ku8Channel);
/* PRQA S 0850 --                                                             */

/******************************************************************************/
/*! \Description Function to create the fullComRequestors data element for a
                 channel.
    \param[in]  ku8Channel The Channel for which fullComRequestors data element
                shall be filled.                                              \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[out] kpudtStruct Pointer to the channel's main function created
                structure.                                                    \n
                \Unit Pointer to ComM_UserHandleArrayType
*******************************************************************************/
#if (ComM_bANY_FCOM_SRI_ENABLE == TRUE)
extern FUNC(void, COMM_CODE) ComM_vidCreateFCOMReqStruct(
                             const NetworkHandleType ku8Channel,
                             ComM_UserHandleArrayType* const kpudtStruct);
#endif /* ComM_bANY_FCOM_SRI_ENABLE */


#if (ComM_bANY_INTERNAL_CHANNEL == TRUE)
/******************************************************************************/
/*! \Description Function to create the current communication mode on an
                 internal channel.
    \param[in]  ku8Channel The Channel for which the current communication mode
                shall be retrieved.                                           \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit NetworkHandleType
    \param[out] pu8ComMModePtr Pointer to the caller's created pointer        \n
                \Unit Pointer to ComM_UserHandleArrayType
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_u8GetInternalBusMode(
                  NetworkHandleType u8Network,
                  P2VAR(ComM_ModeType,AUTOMATIC,COMM_VAR) pu8ComMModePtr);
#endif /* ComM_bANY_INTERNAL_CHANNEL */

#if (ComM_bPNC_SUPPORT == TRUE)

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description Function to evaluate if EIRA/ERA will be handled for this channel
                 the calling main main function.\n
    \param[in]  ku8Channel The CHANNEL_ID .  \n
                \Range 0..(ComM_u16NO_OF_CHANNELS-1)                          \n
                \Unit PNCHandleType
    \param[in]  kbActGWCh Boolean of whether the channel is a Active Gateway
                          or not.                         \n
                \Range TRUE or FALSE
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_vidEraEiraHEvaluate(
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
                                             );
/* PRQA S 0850 --                                                             */

#endif /* ComM_bPNC_SUPPORT */


#define COMM_STOP_SEC_CODE
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/
/* PRQA S 0857 -- */

#endif /* COMM_INTERNAL_H */

/** \} */ /* end of ComM module group */
