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
#if (!defined CANSM_CBK_H)
#define CANSM_CBK_H
/*==================[inclusions]============================================*/

#include <ComStack_Types.h>    /* AUTOSAR communication stack types */

#include <CanSM_Cfg.h>         /* Generated configuration */

#include <CanIf.h>             /* CAN Interface */
#include <Can_GeneralTypes.h>  /* CAN type definitions */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/

#define CANSM_START_SEC_CODE
#include <MemMap.h>

/** \brief This function is called to notify a bus-off event.
 **
 ** This function notifies the CanSM module of a bus-off event
 ** on a CAN controller. The bus-off recovery state machine is
 ** executed for the corresponding network handle.
 **
 ** \param[in] ControllerId CAN controller, which detected a bus-off event.
 **
 ** \ServiceID{4}
 ** \Reentrancy{Reentrant (only for different CanControllers)}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, CANSM_CODE) CanSM_ControllerBusOff (
  uint8 ControllerId
);

/**
 ** \brief This callback shall notify the CanSM module about a CAN controller
 ** mode change.
 **
 ** \param[in] ControllerId CAN controller, whose mode has changed
 ** \param[in] ControllerMode Notified CAN controller mode
 **
 ** \ServiceID{7}
 ** \Reentrancy{Reentrant (only for different CAN controllers)}
 ** \Synchronicity{Synchronous}
 **
 */
extern FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication (
  uint8 ControllerId,
  CanIf_ControllerModeType ControllerMode
);

/** \brief This callback shall notify the CanSM module about a CAN transceiver
 ** mode change.
 **
 ** \param[in] TransceiverId CAN transceiver, whose mode has changed
 ** \param[in] TransceiverMode Notified CAN transceiver mode
 **
 ** \ServiceID{9}
 ** \Reentrancy{Reentrant for different CAN Transceivers}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(void, CANSM_CODE) CanSM_TransceiverModeIndication (
  uint8 TransceiverId,
  CanTrcv_TrcvModeType TransceiverMode
);

#if (CANSM_PNSUPPORT == STD_ON)
/** \brief This callback function shall indicate the CanIf_ClearTrcvWufFlag API
 **        process end for the notified CAN Transceiver.
 **
 ** \param[in] Transceiver Requested Transceiver
 **
 ** \ServiceID{8}
 ** \Reentrancy{Reentrant for different CAN Transceivers}
 ** \Synchronicity{Synchronous}
 */
FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlagIndication (
  uint8 Transceiver
);

/** \brief This callback function indicates the CheckTransceiverWakeFlag API
 **        process end for the notified CAN Transceiver.
 **
 ** \param[in] Transceiver Requested Transceiver
 **
 ** \ServiceID{10}
 ** \Reentrancy{Reentrant for different CAN Transceivers}
 ** \Synchronicity{Synchronous}
 */
FUNC(void, CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication (
  uint8 Transceiver
);

/** \brief This callback function indicates that the transceiver is running in
 **        PN communication mode.
 **
 ** \param[in] TransceiverId CAN transceiver, which was checked for PN availability
 **
 ** \ServiceID{6}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
FUNC(void, CANSM_CODE) CanSM_ConfirmPnAvailability (
  uint8 TransceiverId
);
#endif /* (CANSM_PNSUPPORT == STD_ON) */

#define CANSM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* if !defined( CANSM_CBK_H ) */
/*==================[end of file]===========================================*/

