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
/* !File            : ComM.h                                                  */
/*                                                                            */
/* !Scope           : Public                                                  */
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
/* $Revision::   1.31     $$Author::   MTAYMOUR       $$Date::   Jun 01 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file ComM.h
*
* \par
*   Externals of the module ComM.
*   This file contains the externals of the module ComM. */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module ComM
* This is the grouping of the ComM module members.
* \{
*/
/******************************************************************************/

/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*
$Header::
*/
/* PRQA S 0288 --*/
/******************************************************************************/
/* !VnrOff : Names imposed by AutOSAR Specification                           */
/******************************************************************************/

#ifndef COMM_H
#define COMM_H

/*! Trace_To : ComM-CDD-0240(0) */
#include "ComM_Types.h"

#include "ComM_Cfg.h"

#if (ComM_bRTE_USED == STD_ON)
#include "Rte_ComM_Type.h"
#elif (ComM_bRTE_USED == STD_OFF)
#include "User_ComM_Type.h"
#endif

/******************************************************************************/
/*! \Description Reserved user ID, refer to ComM_UserHandleType.            \n\n
    \Range 255                                                              \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define NOT_USED_USER_ID                  (255)
/******************************************************************************/
/*! \Description Symbol for COMM_NO_COM_NO_PENDING_REQUEST sub-state.       \n\n
    \Range 0                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_NO_COM_NO_PENDING_REQUEST    (0)
/******************************************************************************/
/*! \Description Symbol for COMM_NO_COM_REQUEST_PENDING sub-state.          \n\n
    \Range 1                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_NO_COM_REQUEST_PENDING       (1)
/******************************************************************************/
/*! \Description Symbol for COMM_FULL_COM_NETWORK_REQUESTED sub-state.      \n\n
    \Range 2                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_FULL_COM_NETWORK_REQUESTED   (2)
/******************************************************************************/
/*! \Description Symbol for COMM_FULL_COM_READY_SLEEP sub-state.            \n\n
    \Range 3                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_FULL_COM_READY_SLEEP         (3)
/******************************************************************************/
/*! \Description Symbol for COMM_SILENT_COM sub-state.                      \n\n
    \Range 4                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_SILENT_COM                   (4)




#define COMM_E_MODE_LIMITATION            (0x02)
#define COMM_E_UNINIT                     (0x03)


#if (ComM_bDEV_ERROR_DETECT==STD_ON)

/******************************************************************************/
/*! \Description DET Reported Error Code for: API service used without
                 module initialisation.                                     \n\n
    \Range 1                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_E_NOT_INITED                 (1)
/******************************************************************************/
/*! \Description DET Reported Error Code for: API service used with wrong
                 parameters. (e.g. a NULL pointer)                          \n\n
    \Range 2                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_E_WRONG_PARAMETERS           (2)
/******************************************************************************/
/*! \Description DET Reported Error Code for: Provided API services of other
                 modules returned with an error.                            \n\n
    \Range 3                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_E_ERROR_IN_PROV_SERVICE      (3)


#endif

#define ComM_u8INSTANCE_ID          0x00
#define ComM_u8INIT_ID              0x01
#define ComM_u8DE_INIT_ID           0x02
#define ComM_u8GET_STATE_ID         0x34
#define ComM_u8GET_STATUS_ID        0x03
#define ComM_u8GET_INHIBITION_ST_ID 0x04
#define ComM_u8REQUEST_COM_MODE_ID  0x05
#define ComM_u8GET_MAX_COM_MODE_ID  0x06
#define ComM_u8GET_REQUESTED_COM_ID 0x07
#define ComM_u8GET_CURRENT_COM_M_ID 0x08
#define ComM_u8PREVENT_WAKE_UP_ID   0x09
#define ComM_u8LIMIT_CHANNEL_TO_ID  0x0B
#define ComM_u8LIMIT_ECU_TO_NO_C_ID 0x0C
#define ComM_u8READ_INHIBIT_COUN_ID 0x0D
#define ComM_u8RESET_INHIBIT_COU_ID 0x0E
#define ComM_u8SET_ECU_GROUP_CLA_ID 0x0F
#define ComM_u8GET_VERSION_INFO_ID  0x10
#define ComM_u8NM_NETWORK_START_ID  0x15
#define ComM_u8NM_NETWORK_MODE_ID   0x18
#define ComM_u8NM_PREPARE_BUS_SL_ID 0x19
#define ComM_u8NM_BUS_SLEEP_MODE_ID 0x1A
#define ComM_u8NM_RESTART_INDICA_ID 0x1B
#if (ComM_bCOMM_DCM_ENABLED == TRUE)
#define ComM_u8DCM_ACTIVE_DIAGNO_ID 0x1F
#define ComM_u8DCM_INACTIVE_DIAG_ID 0x20
#endif /* ComM_bCOMM_DCM_ENABLED */
#define ComM_u8ECU_M_WAKE_UP_IND_ID 0x2A
#define ComM_u8COMMUNICATION_ALL_ID 0x35
#define ComM_u8BUS_SM_MODE_INDIC_ID 0x33
#define ComM_u8MAIN_FUNCTION_ID     0x60
#if (ComM_bPNC_SUPPORT == TRUE)
#define ComM_u8COM_CBK_ID       0x7F

/* PRQA S 3453 ++ */
#define u16PNC_CH_REF_SIZE(PNC)  \
    ComM_akudteChannelsPerPnc[PNC].ComM_ku8Size
/* PRQA S 3453 -- */
/* PRQA S 3453 ++ */
#define pu8PNC_CH_REF_ARRAY(PNC) \
    ComM_akudteChannelsPerPnc[PNC].ComM_kpku8ChannelsArray
/* PRQA S 3453 -- */
/* PRQA S 3453 ++ */
#define u8CH_PNC_REF_SIZE(CH)  \
    ComM_akudtePncsPerChannel[CH].ComM_ku8Size
/* PRQA S 3453 -- */
/* PRQA S 3453 ++ */
#define u8CH_PNC_REF_ARRAY(CH) \
    ComM_akudtePncsPerChannel[CH].ComM_kpku8PncsArray
/* PRQA S 3453 -- */
/* PRQA S 3453 ++ */
#define u8PNC_USR_REF_SIZE(PNC)  \
    ComM_akudteUsersPerPnc[PNC].ComM_ku8Size
/* PRQA S 3453 -- */
/* PRQA S 3453 ++ */
#define pu8PNC_USR_REF_ARRAY(PNC) \
    ComM_akudteUsersPerPnc[PNC].ComM_kpku8UsersArray
/* PRQA S 3453 -- */
    
#if (ComM_bPNC_GW_ENABLED == TRUE)

/* PRQA S 3453 ++ */
#define u8CH_ERAPNC_REF_SIZE(CH)  \
    ComM_akudteEraPncsPerCh[CH].ComM_ku8Size
/* PRQA S 3453 -- */
/* PRQA S 3453 ++ */
#define u8CH_ERAPNC_REF_ARRAY(CH) \
    ComM_akudteEraPncsPerCh[CH].ComM_kpku8PncsArray
/* PRQA S 3453 -- */

#endif /*ComM_bPNC_GW_ENABLED */




#endif /* ComM_bPNC_SUPPORT */

#if (ComM_bMODE_LIMIT_ENABLE == TRUE || ComM_bPNC_SUPPORT == TRUE)
/* !Comment: RAM buffer of the NVRAM block */
#define COMM_START_SEC_VAR_UNSPECIFIED
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern VAR(uint8, COMM_VAR) ComM_au8eRamBlk[ComM_u8RAM_BLOCK_SIZE];
/* PRQA S 0850 --                                                             */
#define COMM_STOP_SEC_VAR_UNSPECIFIED
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/
#endif /* ComM_bMODE_LIMIT_ENABLE || ComM_bPNC_SUPPORT */

#define COMM_START_SEC_CODE
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Initialises the ComM module, initialises runtime configurations
 *               with default and/or stored-non-volatile values.
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_Init(void);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description De-Initialises the ComM module, writes configurations that must
                 be stored non-volatile.
*******************************************************************************/
extern FUNC(void, COMM_CODE) ComM_DeInit(void);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to get the current sub-state of a channel.
    \param[in]  Channel The Channel for which the sub-state will be retrieved.\n
                \Range 0..(ComM_u8NO_OF_CHANNELS-1)                           \n
                \Unit NetworkHandleType
    \param[out] State Pointer to the variable in which the sub-state will be
                      stored.                                                 \n
                \Unit ComM_StateType*
    \return     E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetState(
                          NetworkHandleType Channel,
                          P2VAR(ComM_StateType,AUTOMATIC,COMM_APPL_DATA) State);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description Function to get the initialisation status of the ComM Module.
    \param[out] Status  Pointer to the variable in which the initialisation
                        status will be stored.                                \n
                \Unit ComM_InitStatusType*
    \return     E_OK, E_NOT_OK
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus(
                    P2VAR(ComM_InitStatusType,AUTOMATIC,COMM_APPL_DATA) Status);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to get the current Communication Inhibition Status
                 of a channel.                                                \n
                 Configurable ON/OFF via ComM_bMODE_LIMIT_ENABLE. (if there is
                 no mode limitation then the existence of the service is
                 invalid.)
    \param[in]   Channel The Channel for which the Communication Inhibition
                        Status will be retrieved.                             \n
                 \Range 0..(ComM_u8NO_OF_CHANNELS-1)                          \n
                 \Unit NetworkHandleType
    \param[out]  Status  Pointer to the variable in which the Communication
                        Inhibition Status will be stored.                     \n
                 \Unit ComM_InhibitionStatusType*
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus(
              NetworkHandleType Channel,
              P2VAR(ComM_InhibitionStatusType,AUTOMATIC,COMM_APPL_DATA) Status);
#endif /* ComM_bMODE_LIMIT_ENABLE */
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/
/*! \Description Function to request a certain communication mode for a certain
                 user.
    \param[in]   User The User for which the Communication Mode is Requested. \n
                 \Range 0..(ComM_u8NO_OF_USERS-1)                             \n
                 \Unit ComM_UserHandleType
    \param[in]   ComMode The Requested Communication Mode.                    \n
                 \Range COMM_FULL_COMMUNICATION, COMM_NO_COMMUNICATION        \n
                 \Unit ComM_ModeType
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED, COMM_E_MODE_LIMITATION
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode(
                                       ComM_UserHandleType User,
                                       ComM_ModeType ComMode);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to get the current maximum allowed Communication mode
                 of a user.                                                   \n
                 For any channel; if ComMNoCom limitation was active,
                 COMM_NO_COMMUNICATION will be returned, otherwise and also for
                 any channel if ComMNoWakeup limitation was active
                 COMM_SILENT_COMMUNICATION will be returned, otherwise
                 COMM_FULL_COMMUNICATION will be returned.
    \param[in]   User The User for which the maximum allowed Communication Mode
                      will be retrieved.                                      \n
                 \Range 0..(ComM_u8NO_OF_USERS-1)                             \n
                 \Unit ComM_UserHandleType
    \param[out]  ComMode  Pointer to the variable in which the maximum allowed
                          Communication Mode will be stored.                  \n
                 \Range COMM_FULL_COMMUNICATION, COMM_NO_COMMUNICATION        \n
                 \Unit ComM_ModeType*
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode(
                         ComM_UserHandleType User,
                         P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to get the current requested Communication mode of a
                 user.
    \param[in]   User The User for which the requested Communication Mode will
                 be retrieved.                                                \n
                 \Range 0..(ComM_u8NO_OF_USERS-1)                             \n
                 \Unit ComM_UserHandleType
    \param[out]  ComMode  Pointer to the variable in which the Communication
                          Mode will be stored.                                \n
                 \Range COMM_FULL_COMMUNICATION, COMM_NO_COMMUNICATION        \n
                 \Unit ComM_ModeType*
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode(
                         ComM_UserHandleType User,
                         P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to get the current actual Communication mode of a
                 user.                                                        \n
                 Done by querying the BusSMs of the channels assigned for the
                 user for their communication modes and returning the lowest.
    \param[in]   User The User for which the current Communication Mode will be
                      retrieved.                                              \n
                 \Range 0..(ComM_u8NO_OF_USERS-1)                             \n
                 \Unit ComM_UserHandleType
    \param[out]  ComMode Pointer to the variable in which the Communication Mode
                         will be stored.                                      \n
                 \Unit ComM_ModeType*
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode(
                         ComM_UserHandleType User,
                         P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to set a ComMNoWakeup inhibition for a certain
                 channel.                                                     \n
                 Configurable ON/OFF via ComM_bMODE_LIMIT_ENABLE and
                 ComM_bWAKEUP_INH_ENABLE. (i.e. both must be TRUE for the
                 function to exist.)
    \param[in]   Channel The Channel on which the ComMNoWakeup Inhibition status
                        will be set.                                          \n
                 \Range 0..(ComM_u8NO_OF_CHANNELS-1)                          \n
                 \Unit NetworkHandleType
    \param[in]   Status The Status to be set.                                 \n
                 \Unit boolean
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
#if (ComM_bWAKEUP_INH_ENABLE == TRUE)
extern FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp(
                                       NetworkHandleType Channel,
                                       boolean Status);
#endif /* ComM_bWAKEUP_INH_ENABLE */
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to set a ComMNoCom inhibition for a certain channel.\n
                 Configurable ON/OFF via ComM_bMODE_LIMIT_ENABLE.
    \param[in]   Channel The Channel on which the ComMNoCom Inhibition status
                        will be set.                                          \n
                 \Range 0..(ComM_u8NO_OF_CHANNELS-1)                          \n
                 \Unit NetworkHandleType
    \param[in]   Status The Status to be set.                                 \n
                 \Unit boolean
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode(
                                       NetworkHandleType Channel,
                                       boolean Status);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to set a ComMNoCom inhibition for a ALL channels.   \n
                 Configurable ON/OFF via ComM_bMODE_LIMIT_ENABLE.
    \param[in]   Status The Status to be set.                                 \n
                 \Unit boolean
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode(boolean Status);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to get the Inhibited Requests Counter.              \n
                 Configurable ON/OFF via ComM_bMODE_LIMIT_ENABLE.
    \param[out]  CounterValue Pointer to the variable in which the Counter will
                              be stored.                                      \n
                 \Unit boolean
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter(
                           P2VAR(uint16,AUTOMATIC,COMM_APPL_DATA) CounterValue);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to reset the Inhibited Requests Counter.            \n
                 Configurable ON/OFF via ComM_bMODE_LIMIT_ENABLE.
    \return      E_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter(void);
/* PRQA S 0850 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/*! \Description Function to set the ECUGroupClassification global
                 Configuration.                                               \n
                 Configurable ON/OFF via ComM_bMODE_LIMIT_ENABLE.
    \param[out]  Status The Status to be set.                                 \n
                 \Unit ComM_InhibitionStatusType
    \return      E_OK, E_NOT_OK, COMM_E_NOT_INITED
*******************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification(
                                       ComM_InhibitionStatusType Status);
									   
/* PRQA S 0850 --                                                             */
#endif /* ComM_bMODE_LIMIT_ENABLE */
/******************************************************************************/

#if (ComM_bVERSION_INFO_API==STD_ON)
/* !Deviation: [3459] Requirement States that this function should be
    implemented as a macro if source code of caller is available and this is a
    minor rule */
/* PRQA S 3459, 3412 ++ */
/******************************************************************************/
/*! \Description This function returns the ComM module's published
                 information in the provided pointer to Std_VersionInfoType.\n
                 Configurable on/off by the configuration parameter
                 ComM_bVERSION_INFO_API.\n
                 Configurable implementation as a macro and as a function by
                 the configuration parameter ComM_bVER_INFO_CALLER
                 this is the macro implementation.                          \n\n
   \Trace_To ComM-CDD-0156(0), ComM-CDD-0157(0), ComM-CDD-0158(0),
             ComM-CDD-0159(0)
*******************************************************************************/
#if (ComM_bDEV_ERROR_DETECT == STD_ON)
#define ComM_GetVersionInfo(Versioninfo) do {                                  \
    if ((Versioninfo) != NULL_PTR)                                             \
    {                                                                          \
        (Versioninfo)->vendorID = COMM_VENDOR_ID;                              \
        (Versioninfo)->moduleID = COMM_MODULE_ID;                              \
        (Versioninfo)->sw_major_version = COMM_SW_MAJOR_VERSION;               \
        (Versioninfo)->sw_minor_version = COMM_SW_MINOR_VERSION;               \
        (Versioninfo)->sw_patch_version = COMM_SW_PATCH_VERSION;               \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        Det_ReportError(COMM_MODULE_ID, ComM_u8INSTANCE_ID,                    \
                ComM_u8GET_VERSION_INFO_ID, COMM_E_WRONG_PARAMETERS);          \
    }                                                                          \
} while (1==0)
#else  /* ComM_bDEV_ERROR_DETECT */
#define ComM_GetVersionInfo(Versioninfo) do {                                  \
    if ((Versioninfo) != NULL_PTR)                                             \
    {                                                                          \
        (Versioninfo)->vendorID = COMM_VENDOR_ID;                              \
        (Versioninfo)->moduleID = COMM_MODULE_ID;                              \
        (Versioninfo)->sw_major_version = COMM_SW_MAJOR_VERSION;               \
        (Versioninfo)->sw_minor_version = COMM_SW_MINOR_VERSION;               \
        (Versioninfo)->sw_patch_version = COMM_SW_PATCH_VERSION;               \
    }                                                                          \
} while (1==0)
/* PRQA S 3459, 3412 -- */
#endif /* ComM_bDEV_ERROR_DETECT */
#endif /* COMM_bVERSION_INFO_API */
#define COMM_STOP_SEC_CODE
/* PRQA S 0838 ++*/
#include "MemMap.h"
/* PRQA S 0838 --*/

#endif /* COMM_H */
/** \} */ /* end of ComM module group */

