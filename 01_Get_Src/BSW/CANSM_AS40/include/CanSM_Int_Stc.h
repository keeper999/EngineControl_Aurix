/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined CANSM_INT_STC_H)
#define CANSM_INT_STC_H

/*==================[inclusions]============================================*/

#include <ComStack_Types.h>    /* AUTOSAR communication stack types */
#include <ComM.h>              /* Communication Manager types */

/*==================[macros]================================================*/

/*------------------[CanSM macros]-----------*/

/** \brief represents global uninitialized state */
#define CANSM_GLOBAL_UNINIT         0U

/** \brief represents global initialized state */
#define CANSM_GLOBAL_INIT           1U

/** \brief no bus-off event occurred */
#define CANSM_NO_BUS_OFF            0U

/** \brief bus-off event occurred */
#define CANSM_BUS_OFF               1U

/** \brief transceiver id indicating that no transceiver is present */
#define CANSM_TRANSCEIVER_ID_NONE 255U

/** \brief special value: no Dem event id configured (0 is not a valid value for Dem_EventIdType)
 */
#define CANSM_INVALID_DEM_EVENTID   0U

/** \brief indicates that no recovery shall be performed */
#define CANSM_NO_STATE_REQ          0U

/** \brief indicates that recovery to mode FULL_COMMUNICATION shall be performed */
#define CANSM_REQ_STATE_FULL_COM    1U

/** \brief indicates that recovery to mode SILENT_COMMUNICATION shall be performed */
#define CANSM_REQ_STATE_SILENT_COM  2U


/*------------------[Service Ids]-----------*/

/** \brief Service Id of CanSM_Init() */
#define CANSM_SID_INIT 0x00U

/** \brief Service Id of CanSM_GetVersionInfo() */
#define CANSM_SID_GETVERSIONINFO 0x01U

/** \brief Service Id of CanSM_RequestComMode() */
#define CANSM_SID_REQUESTCOMMODE 0x02U

/** \brief Service Id of CanSM_GetCurrentComMode() */
#define CANSM_SID_GETCURRENTCOMMODE 0x03U

/** \brief Service Id of CanSM_ControllerBusOff() */
#define CANSM_SID_CONTROLLERBUSOFF 0x04U

/** \brief Service Id of CanSM_MainFunction() */
#define CANSM_SID_MAINFUNCTION 0x05U

/** \brief Service Id of CanSM_ControllerModeIndication() */
#define CANSM_SID_CONTROLLERMODEINDICATION 0x07U

/** \brief Service Id of CanSM_TransceiverModeIndication() */
#define CANSM_SID_TRANSCEIVERMODEINDICATION 0x09U

/** \brief Service Id of CanSM_ClearTrcvWufFlagIndication() */
#define CANSM_SID_CLEARTRCVWUFFLAGINDICATION 0x08U

/** \brief Service Id of CanSM_CheckTransceiverWakeFlagIndication() */
#define CANSM_SID_CHECKTRANSCEIVERWAKEFLAGINDICATION 0x0aU

/** \brief Service Id of CanSM_ConfirmPnAvailability() */
#define CANSM_SID_CONFIRMPNAVAILABILITY 0x06U

/** \brief Service Id of CanSM_TxTimeoutException() */
#define CANSM_SID_TXTIMEOUTEXCEPTION 0x0bU

/*------------------[Error Ids]-----------*/

/** \brief DET Error Code */
#define CANSM_E_UNINIT 0x01U

/** \brief DET Error Code */
#define CANSM_E_PARAM_POINTER 0x02U

/** \brief DET Error Code */
#define CANSM_E_INVALID_NETWORK_HANDLE 0x03U

/** \brief DET Error Code */
#define CANSM_E_PARAM_CONTROLLER 0x04U

/** \brief DET Error Code */
#define CANSM_E_PARAM_TRANSCEIVER 0x05U

/** \brief DET Error Code */
#define CANSM_E_BUSOFF_RECOVERY_ACTIVE 0x06U

/** \brief DET Error Code */
#define CANSM_E_WAIT_MODE_INDICATION 0x07U

/** \brief DET Error Code */
#define CANSM_E_INVALID_COMM_REQUEST 0x08U

/** \brief DET Error Code: timeout waiting for mode change indication */
#define CANSM_E_MODE_REQUEST_TIMEOUT 0x0AU

/** \brief DET Error Code: Bus-off indication in invalid Com mode (EB enhancement) */
#define CANSM_E_INVALID_BUSOFF_INDICATION 0x0BU

/** \brief DET Error Code: Denied mode req. due to ongoing Tx timeout recovery (EB enhancement) */
#define CANSM_E_TXTIMEOUT_RECOVERY_ACTIVE 0x0CU


/*==================[type definitions]======================================*/

/** \brief type big enough to hold our network indices */
typedef NetworkHandleType CanSM_NetworkIndexType;

/** \brief input type for the bus-off recovery state machine */
typedef enum {
  CANSM_EVENT_TIMER, /**< timer-elapsed event to be handled */
  CANSM_EVENT_BUSOFF /**< bus-off event to be handled */
} CanSM_BorEventType;

/*==================[external constants]====================================*/


/*==================[external data]=========================================*/

#define CANSM_START_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/** \brief A pointer to this variable (with constant value COMM_NO_COMMUNICATION) is passed to
 *  ComM_BusSM_ModeIndication */
extern VAR(ComM_ModeType, CANSM_VAR) CanSM_CommNoCommunication;

/** \brief A pointer to this variable (with constant value COMM_SILENT_COMMUNICATION) is passed to
 *  ComM_BusSM_ModeIndication */
extern VAR(ComM_ModeType, CANSM_VAR) CanSM_CommSilentCommunication;

/** \brief A pointer to this variable (with constant value COMM_FULL_COMMUNICATION) is passed to
 *  ComM_BusSM_ModeIndication */
extern VAR(ComM_ModeType, CANSM_VAR) CanSM_CommFullCommunication;

#define CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>


#define CANSM_START_SEC_VAR_INIT_8
#include <MemMap.h>

/** \brief initialization status (treated boolean) */
extern VAR(uint8, CANSM_VAR) CanSM_GlobalInit;

#define CANSM_STOP_SEC_VAR_INIT_8
#include <MemMap.h>

/*==================[external function declarations]========================*/

#endif /* if !defined( CANSM_INT_STC_H ) */
/*==================[end of file]===========================================*/

