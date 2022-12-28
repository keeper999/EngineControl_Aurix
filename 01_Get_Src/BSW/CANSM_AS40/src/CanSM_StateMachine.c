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

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 16.10 (required)
 *   If a function returns error information, then that error information shall be tested.
 *
 *   Reason:
 *   Failures of CanIf_SetControllerMode or CanIf_SetTrcvMode shall be handled by the timeout of
 *   the respective mode indication CanSM_ControllerModeIndiction/CanSM_TransceiverModeIndication.
 *     If CanIf_SetControllerMode or CanIf_SetTrcvMode do not return E_OK, the CanIf will not issue
 *   the respective mode indication and the CanSM will handle the error after the mode indication
 *   wait timeout. Therefore the error information returned by CanIf_SetControllerMode and
 *   CanIf_SetTrcvMode is not needed for error handling.
 *
 *  MISRA-2) Deviated Rule: 14.1 (required)
 *    There shall be no unreachable code.
 *
 *    Reason:
 *    In case of a single network macros to access the configuration are directly translated to
 *    boolean values which can lead to contraditing condition statments (e.g. TRUE == FALSE).
 *
 *  MISRA-3) Deviated Rule: 13.7 (required)
 *    Boolean operations whose results are invariant shall not be permitted.
 *
 *    Reason:
 *    In case of a single network macros to access the configuration are directly translated to
 *    boolean values which can lead to contraditing condition statments (e.g. TRUE == FALSE).
 */

/*==================[inclusions]============================================*/

#include <CanSM_Trace.h>
#include <TSAutosar.h>              /* EB specific standard types */
#include <ComStack_Types.h>         /* AUTOSAR communication stack types */
#include <TSAtomic_Assign.h>        /* Atomic assignment macros */

#include <CanSM_Cfg.h>              /* Generated configuration */
#include <CanSM_Internal.h>
#include <CanSM_InternalCfg.h>      /* BSWM_CANSM_CURRENTSTATE */
#include <CanSM_BswM.h>

#include <CanIf.h>                  /* CAN Interface */
#include <ComM_BusSm.h>             /* ComM BusSm API */
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>                    /* Development Error Tracer */
#endif

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_START_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */



/* -----------------[ Transitions ]---------------------------------------- */



/**
 * Consists solely of a switch expression to dispatch the corresponding transition.
 *
 * \param[in] nw Network index
 * \param[in] transition Enum value identifying transition
 * \param[in,out] nextTransition If another transition is triggered by the dispatched transition,
 * the function sets this parameter accordingly
 * \param[in] invokedInMainFunction TRUE if and only if transition executes in main function
 * context
 */
STATIC FUNC(void, CANSM_CODE) CanSM_DoTransitionSwitch(
  const CanSM_NetworkIndexType nw,
  const CanSM_TransitionType transition,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition,
  const boolean invokedInMainFunction
);



/* transitions to NOCO */

/**
 * Executes transition CANSM_T_RNOCO_INITIAL.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_RNOCO_DEINIT_INITIAL.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_DEINIT_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_RNOCO_CC_INITIAL.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_CC_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_RNOCO_CC_STOPPED.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_CC_STOPPED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_RNOCO_CC_SLEEP.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_CC_SLEEP(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

#if (CANSM_USE_TRANSCEIVER == STD_ON)

/**
 * Executes transition CANSM_T_RNOCO_TRCV_NORMAL.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_TRCV_NORMAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

/**
 * Executes transition CANSM_T_RNOCO_FINAL.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_FINAL(
  const CanSM_NetworkIndexType nw
);

#if (CANSM_PNSUPPORT == STD_ON)
/* transitions to NOCO with partial networking */

/**
 * Executes transition CANSM_T_PN_DEINIT.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_DEINIT(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_PN_CLEAR_WUF_INDICATED.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_CLEAR_WUF_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_PN_CC_STOPPED_INDICATED.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_CC_STOPPED_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_PN_TRCV_NORMAL_INDICATED.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_TRCV_NORMAL_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_PN_TRCV_STANDBY_INDICATED.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_TRCV_STANDBY_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_PN_CC_SLEEP_INDICATED.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_CC_SLEEP_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_PN_CC_SLEEP_TIMEOUT.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_CC_SLEEP_TIMEOUT(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);
#endif /* CANSM_PNSUPPORT == STD_ON */

/* transitions to FUCO */

/**
 * Executes transition CANSM_T_RFUCO_INITIAL.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

#if (CANSM_USE_TRANSCEIVER == STD_ON)

/**
 * Executes transition CANSM_T_RFUCO_TRCV_INITIAL.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_TRCV_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

#endif /* CANSM_USE_TRANSCEIVER == STD_ON */


/**
 * Executes transition CANSM_T_RFUCO_TRCV_NORMAL.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_TRCV_NORMAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_RFUCO_CC_STOPPED.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_CC_STOPPED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_RFUCO_CC_STARTED.
 *
 * \param[in] nw Network index
 * \param[in] invokedInMainFunction TRUE if and only if transition executes in main function
 * context
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_CC_STARTED(
  const CanSM_NetworkIndexType nw,
  const boolean invokedInMainFunction
);



/* transitions between FUCO and SICO */

/**
 * Executes transition CANSM_T_FUCO_SICO.
 *
 * \param[in] nw Network index
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_FUCO_SICO(
  const CanSM_NetworkIndexType nw
);

/**
 * Executes transition CANSM_T_SICO_FUCO.
 *
 * \param[in] nw Network index
 * \param[in] invokedInMainFunction TRUE if and only if transition executes in main function
 * context
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_SICO_FUCO(
  const CanSM_NetworkIndexType nw,
  const boolean invokedInMainFunction
);



/* bus-off recovery state machine */

/**
 * Executes transition CANSM_T_FUCO_HANDLE_BUS_OFF.
 *
 * \param[in] nw Network index
 * \param[in,out] nextTransition If another transition is triggered by this transition,
 * the function sets this parameter accordingly
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_FUCO_HANDLE_BUS_OFF(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Executes transition CANSM_T_FUCO_TX_OFF.
 *
 * \param[in] nw Network index
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_FUCO_TX_OFF(
  const CanSM_NetworkIndexType nw
);

/**
 * Executes transition CANSM_T_FUCO_TX_ON.
 *
 * \param[in] nw Network index
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_FUCO_TX_ON(
  const CanSM_NetworkIndexType nw
);

/**
 * Executes transition T_FUCO_BUS_OFF_PASSIVE, unless there is a concurrent transition to silent
 * communication.
 *
 * \param[in] nw Network index
 */
STATIC FUNC(void, CANSM_CODE) CanSM_Do_TRY_T_FUCO_BUS_OFF_PASSIVE(
  const CanSM_NetworkIndexType nw
);



/* CanSM_MainFunctionInternal subroutines */

/**
 * Subroutine of CanSM_MainFunctionInternal.
 *
 * \param[in] nw Network index
 * \param[in] internalState Copy of CanSM_MainFunctionInternal local variable
 * \param[in,out] nextTransition If a transition is triggered, the subroutine sets the parameter to
 * the corresponding value
 */
STATIC FUNC(void, CANSM_CODE) CanSM_MainFunctionCheckModeIndications
(
  const CanSM_NetworkIndexType nw,
  const uint8 internalState,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

/**
 * Subroutine of CanSM_MainFunctionInternal.
 *
 * \param[in] nw Network index
 * \param[in] internalState Copy of CanSM_MainFunctionInternal local variable
 * \param[in,out] nextTransition If a transition is triggered, the subroutine sets the parameter to
 * the corresponding value
 */
STATIC FUNC(void, CANSM_CODE) CanSM_MainFunctionRepeatModeRequests
(
  const CanSM_NetworkIndexType nw,
  const uint8 internalState,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
);

#if (CANSM_PNSUPPORT == STD_ON)
/**
 * Handles transition logic subject to Tx timeout recovery
 * (invoked in CanSM_MainFunctionInternal)
 *
 * Handles the decision for a state transition for the recovery triggered
 * by CanSM_TxTimeoutException.
 *
 * \param[in] nw Network index
 * \param[in] reqState
 * \param[in] internalState actual state of the CanSM state machine
 *
 * \return next transition
 * \retval CANSM_T_NONE No transition caused by TxTimeException detected
 * \retval !CANSM_T_NONE Identified transition caused by TxTimeException
 */
STATIC FUNC(CanSM_TransitionType, CANSM_CODE) CanSM_HandleTxTimeoutException
(
  const CanSM_NetworkIndexType nw,
  const uint8 reqState,
  const uint8 internalState
);
#endif /* CANSM_PNSUPPORT == STD_ON */

/* default trailing critical section */

/**
 * Inside a critical section, sets CANSM_NW_INFO_INTERNALSTATE to newInternalState
 *
 * \param[in] nw Network index
 * \param[in] newInternalState New state for CANSM_NW_INFO_INTERNALSTATE
 */
STATIC FUNC(void, CANSM_CODE) CanSM_DefaultTrailingCriticalSection(
  const CanSM_NetworkIndexType nw,
  const uint8 newInternalState
);


/* controller helper functions */

/**
 * Call CanIf_SetPduMode with the passed mode request for each controller.
 *
 * \param[in] nw Network index
 * \param[in] pduModeRequest Mode request
 */
STATIC FUNC(void, CANSM_CODE) CanSM_SetPduModes(
  const CanSM_NetworkIndexType nw,
  const CanIf_PduSetModeType pduModeRequest
);

/**
 * Clears the received mode indication for each controller and then calls
 * CanSM_SetCtrlModes with the passed mode request.
 *
 * \param[in] nw Network index
 * \param[in] ctrlMode Mode request
 * \param[out] allModeIndicationsReceived TRUE if and only if since the last last controller mode
 * indication reset, mode indications for ctrlMode have been received for all controllers
 * (and have not been superseded by other controller mode indications).
 */
STATIC FUNC(void, CANSM_CODE) CanSM_ClearCtrlModeIndAndSetModes(
  const CanSM_NetworkIndexType nw,
  const CanIf_ControllerModeType ctrlMode,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) allModeIndicationsReceived
);

/**
 * Checks if all expected controller mode indications have been received.
 *
 * \param[in] nw Network index
 * \param[in] ctrlMode Expected controller mode
 * \return boolean
 * \retval TRUE Since the last last controller mode indication reset, mode
 * indications for ctrlMode have been received for all controllers (and have not been
 * superseded by other controller mode indications).
 * \retval FALSE Else.
 */
STATIC FUNC(boolean, CANSM_CODE) CanSM_CheckCtrlModeIndications(
  const CanSM_NetworkIndexType nw,
  const CanIf_ControllerModeType ctrlMode
);

/**
 * For each controller for which no corresponding mode indication has been received since
 * the last controller mode indication reset:
 * Call CanIf_SetControllerMode with ctrlMode.
 *
 * \param[in] nw Network index
 * \param[in] ctrlMode Mode request
 * \param[out] allModeIndicationsReceived TRUE if and only if since the last last controller mode
 * indication reset, mode indications for ctrlMode have been received for all controllers
 * (and have not been superseded by other controller mode indications).
 */
STATIC FUNC(void, CANSM_CODE) CanSM_SetCtrlModes(
  const CanSM_NetworkIndexType nw,
  const CanIf_ControllerModeType ctrlMode,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) allModeIndicationsReceived
);

/**
 * Converts CanIf_ControllerModeType to CanSM specific representation.
 *
 * \param[in] ctrlMode Value passed to CanSM_ControllerModeIndication
 * \return CanSM specific representation
 */
STATIC FUNC(uint8, CANSM_CODE) CanSM_ControllerModeTypeToUint8(
  const CanIf_ControllerModeType ctrlMode
);

#if (CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE == STD_ON)
/**
 * Checks if CanIf_GetTxConfirmationState returns CANIF_TX_RX_NOTIFICATION for all controllers of
 * the network.
 *
 * \param[in] nw Network index
 *
 * \return boolean
 * \retval TRUE All CanIf_GetTxConfirmationState returned CANIF_TX_RX_NOTIFICATION.
 * \retval FALSE Else.
 */
STATIC FUNC(boolean, CANSM_CODE) CanSM_CheckCanIfGetTxConfirmationStates(
  const CanSM_NetworkIndexType nw
);
#endif /* CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE == STD_ON */


/* transceiver helper functions */

#if (CANSM_TRCV_RESOURCES == STD_ON)

/**
 * Clears the transceiver mode indication and then calls CanSM_SetTrcvMode with the
 * passed mode request.
 *
 * \param[in] nw Network index
 * \param[in] trcvMode Mode request
 * \param[out] modeIndicationReceived TRUE if and only if since the last transceiver mode
 * indication reset, the trcvMode mode indication has been received
 * (and has not been superseded by other transceiver mode indications).
 */
STATIC FUNC(void, CANSM_CODE) CanSM_ClearTrcvModeIndAndSetMode(
  const CanSM_NetworkIndexType nw,
  const CanTrcv_TrcvModeType trcvMode,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) modeIndicationReceived
);

/**
 * Checks if the expected transceiver mode indication has been received.
 *
 * \param[in] nw Network index
 * \param[in] trcvMode Expected transceiver mode
 * \return boolean
 * \retval TRUE Since the last last transceiver mode indication reset, the trcvMode mode
 * indication has been received (and has not been superseded by other transceiver mode
 * indications).
 * \retval FALSE Else.
 */
STATIC FUNC(boolean, CANSM_CODE) CanSM_CheckTrcvModeIndication(
  const CanSM_NetworkIndexType nw,
  const CanTrcv_TrcvModeType trcvMode
);

/**
 * Calls CanIf_SetTrcvMode with the passed mode request.
 *
 * \param[in] nw Network index
 * \param[in] trcvMode Mode request
 * \param[out] modeIndicationReceived TRUE if and only if since the last transceiver mode
 * indication reset, the trcvMode mode indication has been received (and has not been
 * superseded by other transceiver mode indications).
 */
STATIC FUNC(void, CANSM_CODE) CanSM_SetTrcvMode(
  const CanSM_NetworkIndexType nw,
  const CanTrcv_TrcvModeType trcvMode,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) modeIndicationReceived
);

/**
 * Converts CanTrcv_TrcvModeType to CanSM specific representation.
 *
 * \param[in] trcvMode
 * \return CanSM specific representation
 */
STATIC FUNC(uint8, CANSM_CODE) CanSM_TrcvModeTypeToUint8(
  const CanTrcv_TrcvModeType trcvMode
);

#endif /* CANSM_TRCV_RESOURCES == STD_ON */

/* partial networking helper functions */

#if (CANSM_PNSUPPORT == STD_ON)

/**
 * Calls CanIf_ClearTrcvWufFlag.
 *
 * \param[in] nw Network index
 * \param[out] clearIndicationReceived TRUE if and only if since the last
 * indication reset, the ClearTrcvWufFlag indication has been received.
 */
STATIC FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlag(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) clearIndicationReceived
);

/**
 * Calls CanIf_CheckTrcvWufFlag.
 *
 * \param[in] nw Network index
 * \param[out] checkIndicationReceived TRUE if and only if since the last
 * indication reset, the CheckTrcvWakeFlag indication has been received.
 */
STATIC FUNC(void, CANSM_CODE) CanSM_CheckTrcvWakeFlag (
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) checkIndicationReceived
);

#endif /* CANSM_PNSUPPORT == STD_ON */

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_START_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

FUNC(boolean, CANSM_CODE) CanSM_IsWaitingForModeIndication(
    const uint8 state
)
{
  boolean result = FALSE;

  DBG_CANSM_ISWAITINGFORMODEINDICATION_ENTRY(state);

  switch (state)
  {
#if (CANSM_USE_TRANSCEIVER == STD_ON)
    case CANSM_S_RNOCO_CAN_TRCV_NORMAL:
    case CANSM_S_RNOCO_CAN_TRCV_STANDBY:
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */
    case CANSM_S_RNOCO_CAN_CC_STOPPED:
    case CANSM_S_RNOCO_CAN_CC_SLEEP:
#if (CANSM_PNSUPPORT == STD_ON)
    case CANSM_S_PN_CLEAR_WUF:
    case CANSM_S_PN_CC_STOPPED:
    case CANSM_S_PN_TRCV_NORMAL:
    case CANSM_S_PN_TRCV_STANDBY:
    case CANSM_S_PN_CC_SLEEP:
    case CANSM_S_PN_CHECK_WFLAG_IN_CC_SLEEP:
    case CANSM_S_PN_CHECK_WFLAG_IN_NOT_CC_SLEEP:
#endif /* CANSM_PNSUPPORT == STD_ON */
#if (CANSM_USE_TRANSCEIVER == STD_ON)
    case CANSM_S_RFUCO_CAN_TRCV_NORMAL:
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */
    case CANSM_S_RFUCO_CAN_CC_STOPPED:
    case CANSM_S_RFUCO_CAN_CC_STARTED:
    case CANSM_S_FUCO_RESTART_CC:
      result = TRUE;
      break;
    case CANSM_S_NOIN:
    case CANSM_S_NOCO:
    case CANSM_S_SICO:
    case CANSM_S_FUCO_BUS_OFF_CHECK:
    case CANSM_S_FUCO_NO_BUS_OFF:
    case CANSM_S_FUCO_TX_OFF:
      /* do nothing */
      break;
    /* CHECK: NOPARSE */
    default:
      CANSM_UNREACHABLE_CODE_ASSERT(CANSM_INTERNAL_API_ID);
      break;
    /* CHECK: PARSE */
  }


  DBG_CANSM_ISWAITINGFORMODEINDICATION_EXIT(result,state);
  return result;
}

FUNC(void, CANSM_CODE) CanSM_MainFunctionInternal(
  const CanSM_NetworkIndexType nw
)
{
  /*
   * Overview (Timer/counter management omitted)
   *
   * execute first critical section;
   *
   * if (FUCO && (not waiting for mode indication) && (bus-off flag set))
   * {
   *   set next state transition;
   * }
   * else if (FUCO && (Tx disabled))
   * {
   *   if (CanSMBorTimeL1/CanSMBorTimeL2 timer fires)
   *   {
   *     set next state transition;
   *   }
   * }
   * else if (state CANSM_S_FUCO_BUS_OFF_CHECK)
   * {
   *   if (Tx ensured)
   *   {
   *     set next state transition;
   *   }
   * }
   * else if (CanIf_SetPduMode call in previous CanSM API invocation failed)
   * {
   *   set next state transition to S_RNOCO;
   * }
   * else if (waiting for mode indication)
   * {
   *   if (expected mode indications received)
   *   {
   *     set next state transition;
   *   }
   *   else if (mode request repetition timer fires)
   *   {
   *     if (more than allowed mode request repetitions)
   *     {
   *       report to DEM;
   *       set next state transition to S_RNOCO;
   *     }
   *     else
   *     {
   *       repeat mode request;
   *       if (expected mode indications received)
   *       {
   *         set next state transition;
   *       }
   *     }
   *   }
   * }
   *
   * execute state transition, if set;
   *
   */

  /* caches CANSM_NW_INFO_INTERNALSTATE(nw) */
  uint8 internalState;
#if (CANSM_PNSUPPORT == STD_ON)
  /* caches CANSM_NW_INFO_REQ_STATE(nw) */
  uint8 reqState;
#endif /* CANSM_PNSUPPORT == STD_ON */
  /* caches CANSM_NW_INFO_BUSOFF(nw) */
  uint8 busOff;
  /* caches CANSM_NW_INFO_TIMER(nw) */
  uint16 nwInfoTimer;

  /* by default, don't trigger transition to another state */
  CanSM_TransitionType nextTransition = CANSM_T_NONE;

  /* if we are waiting for a mode indication, write access to shared data
   * needs no protection (except write access to CANSM_NW_INFO_INTERNALSTATE,
   * CANSM_NW_INFO_STATE)
   */
  boolean isWaitingForModeIndication;

  DBG_CANSM_MAINFUNCTIONINTERNAL_ENTRY(nw);

  CANSM_ENTER_CRITICAL_SECTION();
  {
    internalState = CANSM_NW_INFO_INTERNALSTATE(nw);
#if (CANSM_PNSUPPORT == STD_ON)
    reqState = CANSM_NW_INFO_REQ_STATE(nw);
#endif /* CANSM_PNSUPPORT == STD_ON */
    TS_AtomicAssign8(busOff, CANSM_NW_INFO_BUSOFF(nw));

    if (CANSM_NW_INFO_TIMER(nw) != 0U)
    {
      CANSM_NW_INFO_TIMER(nw)--;
    }

    nwInfoTimer = CANSM_NW_INFO_TIMER(nw);
  }

#if (CANSM_PNSUPPORT == STD_ON)
  if ( reqState != CANSM_NO_STATE_REQ )
  {
      nextTransition = CanSM_HandleTxTimeoutException(nw, reqState, internalState);
  }
  /* else: no timeout exception indicated, continue to check for other transitions */
#endif /* CANSM_PNSUPPORT == STD_ON */

  CANSM_EXIT_CRITICAL_SECTION();

  isWaitingForModeIndication = CanSM_IsWaitingForModeIndication(internalState);

#if (CANSM_PNSUPPORT == STD_ON)
  if ( nextTransition == CANSM_T_NONE )
#endif /* CANSM_PNSUPPORT == STD_ON */
  {
    if (
         (busOff == CANSM_BUS_OFF)
         &&
         /* FUCO and not waiting for mode indication */
         (
             (internalState == CANSM_S_FUCO_BUS_OFF_CHECK)
             ||
             (internalState == CANSM_S_FUCO_NO_BUS_OFF)
           )
         )
    {
      /*
       * since CanSM_RequestComMode also checks bus-off flag within critical section,
       * we can be sure it denies a request to leave FUCO if a bus-off is detected here
       */

      nextTransition = CANSM_T_FUCO_HANDLE_BUS_OFF;
    }
    else if (internalState == CANSM_S_FUCO_TX_OFF)
    {
      if (nwInfoTimer == 0U)
      {
        nextTransition = CANSM_T_FUCO_TX_ON;
      }
    }
    else if (internalState == CANSM_S_FUCO_BUS_OFF_CHECK)
    {
#if (CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE == STD_ON)
      /* Deviation MISRA-3 */
      if (CANSM_BOR_TX_CONFIRMATION_POLLING(nw) == TRUE)
      {
        if (CanSM_CheckCanIfGetTxConfirmationStates(nw) == TRUE)
        {
          nextTransition = CANSM_TRY_T_FUCO_BUS_OFF_PASSIVE;
        }
      }
#if (CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON)
      else
#endif /* CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON */
#endif /* CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE == STD_ON */
#if (CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON)
      {
        if (nwInfoTimer == 0U)
        {
          nextTransition = CANSM_TRY_T_FUCO_BUS_OFF_PASSIVE;
        }
      }
#endif /* CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON */
    }
    else if (isWaitingForModeIndication == TRUE)
    {
      /* accesses to most shared data are safe, since there is a pending mode request */

      CanSM_MainFunctionCheckModeIndications(nw, internalState, &nextTransition);

      /* if mode indications are still pending */
      if (nextTransition == CANSM_T_NONE)
      {
        /* Mode repetition counter must be greater than zero if waiting for a mode indication */
        CANSM_PRECONDITION_ASSERT(CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER(nw) != 0U,
                                  CANSM_SID_MAINFUNCTION
                                 );

        /* let time progress */
        CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER(nw)--;

        /* check if mode request repetition timer fires */
        if (CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER(nw) == 0U)
        {
          if (CANSM_NW_INFO_MODE_REQUEST_REPETITION_COUNTER(nw) == 0U)
          {
            /* maximum repetition count exceeded, begin transitions to NOCO */

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
            CANSM_DET_WITH_INSTANCEID(
                CANSM_NW_HANDLE_FROM_IDX(nw),
                CANSM_SID_MAINFUNCTION,
                CANSM_E_MODE_REQUEST_TIMEOUT
            );
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */

            if (
                 (internalState == CANSM_S_FUCO_RESTART_CC)
                 ||
                 (internalState == CANSM_S_RFUCO_CAN_CC_STARTED)
                 ||
                 (internalState == CANSM_S_RFUCO_CAN_CC_STOPPED)
               )
            {
              /* If RFUCO is entered from outside choose INITIAL sequence to
               * execute effect E_PRE_NO_COM (see SWS Figure 7-1). */
              nextTransition = CANSM_T_RNOCO_INITIAL;
            }
#if (CANSM_USE_TRANSCEIVER == STD_ON)
            /* Separate condition dependent on preprocessor from if statement. see [BSWM_C_042] */
            else if (internalState == CANSM_S_RFUCO_CAN_TRCV_NORMAL)
            {
              /* If RFUCO is entered from outside choose INITIAL sequence to
               * execute effect E_PRE_NO_COM (see SWS Figure 7-1). */
              nextTransition = CANSM_T_RNOCO_INITIAL;
            }
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */
            else
            {
              /* If actual state is already a substate of RFUCO choose the decision point
               * between Partial network / no partial network and don't execute effect
               * E_PRE_NO_COM again (see SWS Figure 7-2). */
              nextTransition = CANSM_T_RNOCO_DEINIT_INITIAL;
            }
          }
          else
          {
            CanSM_MainFunctionRepeatModeRequests(nw, internalState, &nextTransition);

            if (nextTransition == CANSM_T_NONE)
            {
              /* after mode request repetition, decrement counter, restart timer  */
              CANSM_NW_INFO_MODE_REQUEST_REPETITION_COUNTER(nw)--;
              CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER(nw) = CANSM_MODEREQ_REPEAT_TIME;
            }
          }
        }
      }
    }
    else
    {
      /* do nothing */
    }
  }
  /* else: do nothing */

  if (nextTransition != CANSM_T_NONE)
  {
    CanSM_DoTransitionSequence(nw, nextTransition, TRUE);
  }

  DBG_CANSM_MAINFUNCTIONINTERNAL_EXIT(nw);
}

FUNC(void, CANSM_CODE) CanSM_DoTransitionSequence(
  const CanSM_NetworkIndexType nw,
  const CanSM_TransitionType initialTransition,
  const boolean invokedInMainFunction
)
{
  /*
   * Overview
   *
   * do
   * {
   *   switch (transition)
   *   {
   *     case some transition:
   *       execute transition;
   *       if (...)
   *       {
   *         set next transition;
   *       }
   *       if (...)
   *       {
   *         execute critical section;
   *       }
   *       break;
   *   }
   * } while (next transition set);
   *
   */

  CanSM_TransitionType nextTransition = initialTransition;

  DBG_CANSM_DOTRANSITIONSEQUENCE_ENTRY(nw,initialTransition,invokedInMainFunction);

  CANSM_PRECONDITION_ASSERT(initialTransition != CANSM_T_NONE, CANSM_INTERNAL_API_ID);

  /* during transition CANSM_TRY_T_FUCO_BUS_OFF_PASSIVE, don't modify shared state outside of
   * critical section */
  if (nextTransition != CANSM_TRY_T_FUCO_BUS_OFF_PASSIVE)
  {

    /* - when changing state, reset mode request repetition counter/timer before trailing
     *   critical section
     * - if not in main function context, increment timer value by 1, since next main function
     *   invocation might happen immediately after this transition
     */
    CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER(nw) =
      invokedInMainFunction ? CANSM_MODEREQ_REPEAT_TIME : (CANSM_MODEREQ_REPEAT_TIME + 1U);
    CANSM_NW_INFO_MODE_REQUEST_REPETITION_COUNTER(nw) = CANSM_MODEREQ_MAX;
  }



  /* loop until requested mode is reached or mode indication is pending */
  /* (synchronous mode indications trigger next transition) */
  do /* ... while (nextTransition != CANSM_T_NONE) */
  {
    const CanSM_TransitionType transition = nextTransition;

    nextTransition = CANSM_T_NONE;

    CanSM_DoTransitionSwitch(
      nw,
      transition,
      &nextTransition,
      invokedInMainFunction
    );

  } while (nextTransition != CANSM_T_NONE);

  DBG_CANSM_DOTRANSITIONSEQUENCE_EXIT(nw,initialTransition,invokedInMainFunction);
}

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

/*==================[internal function definitions]=========================*/

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_START_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */



/* -----------------[ Transitions ]---------------------------------------- */

STATIC FUNC(void, CANSM_CODE) CanSM_DoTransitionSwitch(
  const CanSM_NetworkIndexType nw,
  const CanSM_TransitionType transition,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition,
  const boolean invokedInMainFunction
)
{

  DBG_CANSM_DOTRANSITIONSWITCH_ENTRY(nw,transition,nextTransition,invokedInMainFunction);
  switch (transition)
  {
    /* transitions to NOCO */

    case CANSM_T_RNOCO_INITIAL:
      CanSM_Do_T_RNOCO_INITIAL(nw, nextTransition);
      break;
    case CANSM_T_RNOCO_DEINIT_INITIAL:
      CanSM_Do_T_RNOCO_DEINIT_INITIAL(nw, nextTransition);
      break;

    case CANSM_T_RNOCO_CC_INITIAL:
      CanSM_Do_T_RNOCO_CC_INITIAL(nw, nextTransition);
      break;
    case CANSM_T_RNOCO_CC_STOPPED:
      CanSM_Do_T_RNOCO_CC_STOPPED(nw, nextTransition);
      break;
    case CANSM_T_RNOCO_CC_SLEEP:
      CanSM_Do_T_RNOCO_CC_SLEEP(nw, nextTransition);
      break;
#if (CANSM_USE_TRANSCEIVER == STD_ON)
    case CANSM_T_RNOCO_TRCV_NORMAL:
      CanSM_Do_T_RNOCO_TRCV_NORMAL(nw, nextTransition);
      break;
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */
    case CANSM_T_RNOCO_FINAL:
      CanSM_Do_T_RNOCO_FINAL(nw);
      break;

#if (CANSM_PNSUPPORT == STD_ON)
    /* transitions to NOCO with partial networking */
  case CANSM_T_PN_DEINIT:
      CanSM_Do_T_PN_DEINIT(nw,nextTransition);
      break;
  case CANSM_T_PN_CLEAR_WUF_INDICATED:
      CanSM_Do_T_PN_CLEAR_WUF_INDICATED(nw,nextTransition);
      break;
  case CANSM_T_PN_CC_STOPPED_INDICATED:
      CanSM_Do_T_PN_CC_STOPPED_INDICATED(nw,nextTransition);
      break;
  case CANSM_T_PN_TRCV_NORMAL_INDICATED:
      CanSM_Do_T_PN_TRCV_NORMAL_INDICATED(nw,nextTransition);
      break;
  case CANSM_T_PN_TRCV_STANDBY_INDICATED:
      CanSM_Do_T_PN_TRCV_STANDBY_INDICATED(nw,nextTransition);
      break;
  case CANSM_T_PN_CC_SLEEP_INDICATED:
      CanSM_Do_T_PN_CC_SLEEP_INDICATED(nw,nextTransition);
      break;
  case CANSM_T_PN_CC_SLEEP_TIMEOUT:
      CanSM_Do_T_PN_CC_SLEEP_TIMEOUT(nw,nextTransition);
      break;
#endif /* CANSM_PNSUPPORT == STD_ON */

    /* transitions to FUCO */

    case CANSM_T_RFUCO_INITIAL:
      CanSM_Do_T_RFUCO_INITIAL(nw, nextTransition);
      break;

#if (CANSM_USE_TRANSCEIVER == STD_ON)
    case CANSM_T_RFUCO_TRCV_INITIAL:
      CanSM_Do_T_RFUCO_TRCV_INITIAL(nw, nextTransition);
      break;
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

    case CANSM_T_RFUCO_TRCV_NORMAL:
      CanSM_Do_T_RFUCO_TRCV_NORMAL(nw, nextTransition);
      break;
    case CANSM_T_RFUCO_CC_STOPPED:
      CanSM_Do_T_RFUCO_CC_STOPPED(nw, nextTransition);
      break;
    case CANSM_T_RFUCO_CC_STARTED:
      CanSM_Do_T_RFUCO_CC_STARTED(nw, invokedInMainFunction);
      break;

    /* transitions between FUCO and SICO */

    case CANSM_T_FUCO_SICO:
      CanSM_Do_T_FUCO_SICO(nw);
      break;

    case CANSM_T_SICO_FUCO:
      CanSM_Do_T_SICO_FUCO(nw, invokedInMainFunction);
      break;

    /* bus-off recovery state machine */

    case CANSM_T_FUCO_HANDLE_BUS_OFF:
      CanSM_Do_T_FUCO_HANDLE_BUS_OFF(nw, nextTransition);
      break;
    case CANSM_T_FUCO_TX_OFF:
      CanSM_Do_T_FUCO_TX_OFF(nw);
      break;
    case CANSM_T_FUCO_TX_ON:
      CanSM_Do_T_FUCO_TX_ON(nw);
      break;

    case CANSM_TRY_T_FUCO_BUS_OFF_PASSIVE:
      CanSM_Do_TRY_T_FUCO_BUS_OFF_PASSIVE(nw);
      break;

    /* CHECK: NOPARSE */
    default:
      CANSM_UNREACHABLE_CODE_ASSERT(CANSM_INTERNAL_API_ID);
      break;
    /* CHECK: PARSE */

  } /* end transition switch */

  DBG_CANSM_DOTRANSITIONSWITCH_EXIT(nw,transition,nextTransition,invokedInMainFunction);
}



/* transitions to NOCO */

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  DBG_CANSM_DO_T_RNOCO_INITIAL_ENTRY(nw,nextTransition);

  /* Effect E_PRE_NO_COM (and E_PRE_NOCOM) of figure 7-1 in CanSM SWS. */
  BSWM_CANSM_CURRENTSTATE(CANSM_NW_HANDLE_FROM_IDX(nw), CANSM_BSWM_NO_COMMUNICATION);
  /* and the refined extension for CanIf_SetPduMode. */
  CanSM_SetPduModes(nw, CANIF_SET_OFFLINE);

  /* default value set to state machine deinitialization without partial network. */
  *nextTransition = CANSM_T_RNOCO_DEINIT_INITIAL;

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  DBG_CANSM_DO_T_RNOCO_INITIAL_EXIT(nw,nextTransition);
}


STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_DEINIT_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  DBG_CANSM_DO_T_RNOCO_DEINIT_INITIAL_ENTRY(nw,nextTransition);

  /* default value set to state machine deinitialization without partial network. */
  *nextTransition = CANSM_T_RNOCO_CC_INITIAL;

  /* only select partial network deinitialization if
   * a) partial network support enabled global AND
   * b) partial network enabled for this specific network AND
   * c) transceiver enabled global AND
   * d) transceiver enabled for this specific network */
#if (CANSM_TRANSCEIVERS_NUM > 0U) /* c */
#if (CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM)
  if (CANSM_NW_CONFIG_TRCV_ID(nw) != CANSM_TRANSCEIVER_ID_NONE) /* d */
#endif /* CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM */
  {
#if (CANSM_PNSUPPORT == STD_ON) /* a */
    /* Deviation MISRA-3 */
    if( CANSM_PARTIALNETWORKING(nw) == TRUE ) /* b */
    {
      /* Deviation MISRA-2 */
      *nextTransition = CANSM_T_PN_DEINIT;
    }
#endif /* (CANSM_PNSUPPORT == STD_ON) */
  }
#endif /* CANSM_TRANSCEIVERS_NUM > 0U */

#if ((CANSM_TRANSCEIVERS_NUM == 0U) || (CANSM_TRANSCEIVERS_NUM == CANSM_NETWORKS_NUM))
  TS_PARAM_UNUSED(nw);
#endif /* (CANSM_TRANSCEIVERS_NUM == 0U) || (CANSM_TRANSCEIVERS_NUM == CANSM_NETWORKS_NUM) */

  DBG_CANSM_DO_T_RNOCO_DEINIT_INITIAL_EXIT(nw,nextTransition);
}


STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_CC_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_RNOCO_CC_INITIAL_ENTRY(nw,nextTransition);

  CanSM_ClearCtrlModeIndAndSetModes(nw,
                                    CANIF_CS_STOPPED,
                                    &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_RNOCO_CC_STOPPED;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_RNOCO_CAN_CC_STOPPED);
  }

  DBG_CANSM_DO_T_RNOCO_CC_INITIAL_EXIT(nw,nextTransition);
}


STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_CC_STOPPED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_RNOCO_CC_STOPPED_ENTRY(nw,nextTransition);

  CanSM_ClearCtrlModeIndAndSetModes(nw,
                                    CANIF_CS_SLEEP,
                                    &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_RNOCO_CC_SLEEP;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_RNOCO_CAN_CC_SLEEP);
  }

  DBG_CANSM_DO_T_RNOCO_CC_STOPPED_EXIT(nw,nextTransition);
}


STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_CC_SLEEP(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  DBG_CANSM_DO_T_RNOCO_CC_SLEEP_ENTRY(nw,nextTransition);

#if (CANSM_TRANSCEIVERS_NUM > 0U)
#if (CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM)
  if (CANSM_NW_CONFIG_TRCV_ID(nw) != CANSM_TRANSCEIVER_ID_NONE)
#endif /* CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM */
  {
    boolean allModeIndicationsReceived = FALSE;

    CanSM_ClearTrcvModeIndAndSetMode(nw,
                                     CANTRCV_TRCVMODE_NORMAL,
                                     &allModeIndicationsReceived);
    if (allModeIndicationsReceived == TRUE)
    {
      *nextTransition = CANSM_T_RNOCO_TRCV_NORMAL;
    }
    else
    {
      CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_RNOCO_CAN_TRCV_NORMAL);
    }
  }
#if (CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM)
  else
  {
    *nextTransition = CANSM_T_RNOCO_FINAL;
  }
#endif /* CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM */
#else /* CANSM_TRANSCEIVERS_NUM > 0U */

  *nextTransition = CANSM_T_RNOCO_FINAL;

  TS_PARAM_UNUSED(nw);
#endif /* CANSM_TRANSCEIVERS_NUM > 0U */

  DBG_CANSM_DO_T_RNOCO_CC_SLEEP_EXIT(nw,nextTransition);
}


#if (CANSM_USE_TRANSCEIVER == STD_ON)

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_TRCV_NORMAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_RNOCO_TRCV_NORMAL_ENTRY(nw,nextTransition);

  CanSM_ClearTrcvModeIndAndSetMode(nw,
                                   CANTRCV_TRCVMODE_STANDBY,
                                   &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_RNOCO_FINAL;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_RNOCO_CAN_TRCV_STANDBY);
  }

  DBG_CANSM_DO_T_RNOCO_TRCV_NORMAL_EXIT(nw,nextTransition);
}

#endif /* CANSM_USE_TRANSCEIVER == STD_ON */


STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RNOCO_FINAL(
  const CanSM_NetworkIndexType nw
)
{
  /* in the initial transition to no communication, don't notify ComM, which may not be
   * initialized */
  boolean isInitialTransition = FALSE;

  DBG_CANSM_DO_T_RNOCO_FINAL_ENTRY(nw);

  if (CANSM_NW_INFO_STATE(nw) == CANSM_UNINITED)
  {
    isInitialTransition = TRUE;
  }

  CANSM_ENTER_CRITICAL_SECTION();
  {
    uint8 buf = CANSM_NO_COMMUNICATION;
    TS_AtomicAssign8(CANSM_NW_INFO_STATE(nw), buf);

    /* change to NOCO before notifying other modules */
    DBG_CANSM_INTERNALSTATE_GRP(nw, (CANSM_NW_INFO_INTERNALSTATE(nw)), (CANSM_S_NOCO));
    CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_NOCO;
  }
  CANSM_EXIT_CRITICAL_SECTION();

  if (isInitialTransition == FALSE)
  {
    /* Effect E_NOCOM in figure 7-1 */
    ComM_BusSM_ModeIndication(CANSM_NW_HANDLE_FROM_IDX(nw), &CanSM_CommNoCommunication);
  }

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  DBG_CANSM_DO_T_RNOCO_FINAL_EXIT(nw);
}


/* transitions to NOCO with partial networking */

#if (CANSM_PNSUPPORT == STD_ON)

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_DEINIT(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean clearIndicationReceived = FALSE;

  DBG_CANSM_DO_T_PN_DEINIT_ENTRY(nw,nextTransition);

  /* reset indication flag */
  TS_AtomicAssign8(CANSM_NW_INFO_TRCVCLEARWUFINDICATION(nw), FALSE);

  CanSM_ClearTrcvWufFlag(nw, &clearIndicationReceived);

  if (clearIndicationReceived == TRUE)
  {
    *nextTransition = CANSM_T_PN_CLEAR_WUF_INDICATED;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_PN_CLEAR_WUF);
  }

  DBG_CANSM_DO_T_PN_DEINIT_EXIT(nw,nextTransition);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_CLEAR_WUF_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_PN_CLEAR_WUF_INDICATED_ENTRY(nw,nextTransition);

  CanSM_ClearCtrlModeIndAndSetModes(nw,
                                    CANIF_CS_STOPPED,
                                    &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_PN_CC_STOPPED_INDICATED;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_PN_CC_STOPPED);
  }

  DBG_CANSM_DO_T_PN_CLEAR_WUF_INDICATED_EXIT(nw,nextTransition);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_CC_STOPPED_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_PN_CC_STOPPED_INDICATED_ENTRY(nw,nextTransition);

  CanSM_ClearTrcvModeIndAndSetMode(nw,
                                   CANTRCV_TRCVMODE_NORMAL,
                                   &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_PN_TRCV_NORMAL_INDICATED;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_PN_TRCV_NORMAL);
  }

  DBG_CANSM_DO_T_PN_CC_STOPPED_INDICATED_EXIT(nw,nextTransition);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_TRCV_NORMAL_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_PN_TRCV_NORMAL_INDICATED_ENTRY(nw,nextTransition);

  CanSM_ClearTrcvModeIndAndSetMode(nw,
                                   CANTRCV_TRCVMODE_STANDBY,
                                   &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_PN_TRCV_STANDBY_INDICATED;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_PN_TRCV_STANDBY);
  }

  DBG_CANSM_DO_T_PN_TRCV_NORMAL_INDICATED_EXIT(nw,nextTransition);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_TRCV_STANDBY_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_PN_TRCV_STANDBY_INDICATED_ENTRY(nw,nextTransition);

  CanSM_ClearCtrlModeIndAndSetModes(nw,
                                    CANIF_CS_SLEEP,
                                    &allModeIndicationsReceived);

  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_PN_CC_SLEEP_INDICATED;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_PN_CC_SLEEP);
  }

  DBG_CANSM_DO_T_PN_TRCV_STANDBY_INDICATED_EXIT(nw,nextTransition);
}


STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_CC_SLEEP_INDICATED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean checkIndicationReceived = FALSE;

  DBG_CANSM_DO_T_PN_CC_SLEEP_INDICATED_ENTRY(nw,nextTransition);

  /* reset indication flag */
  TS_AtomicAssign8(CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION(nw), FALSE);

  CanSM_CheckTrcvWakeFlag(nw, &checkIndicationReceived);

  if (checkIndicationReceived == TRUE)
  {
    *nextTransition = CANSM_T_RNOCO_FINAL;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_PN_CHECK_WFLAG_IN_CC_SLEEP);
  }

  DBG_CANSM_DO_T_PN_CC_SLEEP_INDICATED_EXIT(nw,nextTransition);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_PN_CC_SLEEP_TIMEOUT(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean checkIndicationReceived = FALSE;

  DBG_CANSM_DO_T_PN_CC_SLEEP_TIMEOUT_ENTRY(nw,nextTransition);

  /* reset indication flag */
  TS_AtomicAssign8(CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION(nw), FALSE);

  CanSM_CheckTrcvWakeFlag(nw, &checkIndicationReceived);

  if (checkIndicationReceived == TRUE)
  {
    *nextTransition = CANSM_T_PN_DEINIT;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_PN_CHECK_WFLAG_IN_NOT_CC_SLEEP);
  }

  DBG_CANSM_DO_T_PN_CC_SLEEP_TIMEOUT_EXIT(nw,nextTransition);
}

#endif /* (CANSM_PNSUPPORT == STD_ON) */





/* transitions to FUCO */

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  DBG_CANSM_DO_T_RFUCO_INITIAL_ENTRY(nw,nextTransition);

#if (CANSM_TRANSCEIVERS_NUM > 0U)
#if (CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM)
  if (CANSM_NW_CONFIG_TRCV_ID(nw) != CANSM_TRANSCEIVER_ID_NONE)
#endif /* CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM */
  {
    *nextTransition = CANSM_T_RFUCO_TRCV_INITIAL;
  }
#if (CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM)
  else
#endif /* CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM */
#endif /* CANSM_TRANSCEIVERS_NUM > 0U */
#if (CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM)
  {
    *nextTransition = CANSM_T_RFUCO_TRCV_NORMAL;
  }
#endif /* CANSM_TRANSCEIVERS_NUM < CANSM_NETWORKS_NUM */

#if ((CANSM_TRANSCEIVERS_NUM == 0U) || (CANSM_TRANSCEIVERS_NUM == CANSM_NETWORKS_NUM))

  TS_PARAM_UNUSED(nw);
#endif /* (CANSM_TRANSCEIVERS_NUM == 0U) || (CANSM_TRANSCEIVERS_NUM == CANSM_NETWORKS_NUM) */

  DBG_CANSM_DO_T_RFUCO_INITIAL_EXIT(nw,nextTransition);
}


#if (CANSM_USE_TRANSCEIVER == STD_ON)

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_TRCV_INITIAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_RFUCO_TRCV_INITIAL_ENTRY(nw,nextTransition);

  CanSM_ClearTrcvModeIndAndSetMode(nw,
                                   CANTRCV_TRCVMODE_NORMAL,
                                   &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_RFUCO_TRCV_NORMAL;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_RFUCO_CAN_TRCV_NORMAL);
  }

  DBG_CANSM_DO_T_RFUCO_TRCV_INITIAL_EXIT(nw,nextTransition);
}

#endif /* CANSM_USE_TRANSCEIVER == STD_ON */


STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_TRCV_NORMAL(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_RFUCO_TRCV_NORMAL_ENTRY(nw,nextTransition);

  CanSM_ClearCtrlModeIndAndSetModes(nw,
                                    CANIF_CS_STOPPED,
                                    &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_RFUCO_CC_STOPPED;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_RFUCO_CAN_CC_STOPPED);
  }

  DBG_CANSM_DO_T_RFUCO_TRCV_NORMAL_EXIT(nw,nextTransition);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_CC_STOPPED(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_RFUCO_CC_STOPPED_ENTRY(nw,nextTransition);

  {
    /* reset bus-off flag before starting controllers */
    uint8 buf = CANSM_NO_BUS_OFF;
    TS_AtomicAssign8(CANSM_NW_INFO_BUSOFF(nw), buf);
  }

  CanSM_ClearCtrlModeIndAndSetModes(nw,
                                    CANIF_CS_STARTED,
                                    &allModeIndicationsReceived);
  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_RFUCO_CC_STARTED;
  }
  else
  {
    CanSM_DefaultTrailingCriticalSection(nw, CANSM_S_RFUCO_CAN_CC_STARTED);
  }

  DBG_CANSM_DO_T_RFUCO_CC_STOPPED_EXIT(nw,nextTransition);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_RFUCO_CC_STARTED(
  const CanSM_NetworkIndexType nw,
  const boolean invokedInMainFunction
)
{
  DBG_CANSM_DO_T_RFUCO_CC_STARTED_ENTRY(nw,invokedInMainFunction);

  /* reset bus-off counter before entering full communication */
  CANSM_NW_INFO_BOR_COUNTER(nw) = 0U;

  BSWM_CANSM_CURRENTSTATE(CANSM_NW_HANDLE_FROM_IDX(nw), CANSM_BSWM_FULL_COMMUNICATION);

  CanSM_SetPduModes(nw, CANIF_SET_ONLINE);

  CANSM_ENTER_CRITICAL_SECTION();
  {
    uint8 buf = CANSM_FULL_COMMUNICATION;
    TS_AtomicAssign8(CANSM_NW_INFO_STATE(nw), buf);

    /* change to FUCO before notifying other modules */
    DBG_CANSM_INTERNALSTATE_GRP(nw, (CANSM_NW_INFO_INTERNALSTATE(nw)), (CANSM_S_FUCO_BUS_OFF_CHECK));
    CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_FUCO_BUS_OFF_CHECK;

#if (CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON)
    /* Deviation MISRA-3 */
    if (CANSM_BOR_TX_CONFIRMATION_POLLING(nw) == FALSE)
    {
      CANSM_NW_INFO_TIMER(nw) = invokedInMainFunction ?
                                CANSM_BOR_TIME_TX_ENSURED(nw) :
                                (CANSM_BOR_TIME_TX_ENSURED(nw) + 1U);
    }
#else /* CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON */
    TS_PARAM_UNUSED(invokedInMainFunction);
#endif /* CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON */
  }
  CANSM_EXIT_CRITICAL_SECTION();

  ComM_BusSM_ModeIndication(CANSM_NW_HANDLE_FROM_IDX(nw), &CanSM_CommFullCommunication);

  DBG_CANSM_DO_T_RFUCO_CC_STARTED_EXIT(nw,invokedInMainFunction);
}



/* transitions between FUCO and SICO */

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_FUCO_SICO(
  const CanSM_NetworkIndexType nw
)
{

  DBG_CANSM_DO_T_FUCO_SICO_ENTRY(nw);
  BSWM_CANSM_CURRENTSTATE(CANSM_NW_HANDLE_FROM_IDX(nw), CANSM_BSWM_SILENT_COMMUNICATION);

  CanSM_SetPduModes(nw, CANIF_SET_ONLINE);
  CanSM_SetPduModes(nw, CANIF_SET_TX_OFFLINE);

  /* internal state was already updated in CanSM_RequestComModeInternal() to prevent race
   * condition */

  TS_AtomicAssign8(CANSM_NW_INFO_STATE(nw), CANSM_SILENT_COMMUNICATION);

  ComM_BusSM_ModeIndication(CANSM_NW_HANDLE_FROM_IDX(nw), &CanSM_CommSilentCommunication);

  DBG_CANSM_DO_T_FUCO_SICO_EXIT(nw);
}


STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_SICO_FUCO(
  const CanSM_NetworkIndexType nw,
  const boolean invokedInMainFunction
)
{

  DBG_CANSM_DO_T_SICO_FUCO_ENTRY(nw,invokedInMainFunction);
  BSWM_CANSM_CURRENTSTATE(CANSM_NW_HANDLE_FROM_IDX(nw), CANSM_BSWM_FULL_COMMUNICATION);

  CanSM_SetPduModes(nw, CANIF_SET_ONLINE);

  CANSM_ENTER_CRITICAL_SECTION();
  {
    uint8 buf = CANSM_FULL_COMMUNICATION;
    TS_AtomicAssign8(CANSM_NW_INFO_STATE(nw), buf);

    DBG_CANSM_INTERNALSTATE_GRP(nw, (CANSM_NW_INFO_INTERNALSTATE(nw)), (CANSM_S_FUCO_BUS_OFF_CHECK));
    CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_FUCO_BUS_OFF_CHECK;

#if (CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON)
    /* Deviation MISRA-3 */
    if (CANSM_BOR_TX_CONFIRMATION_POLLING(nw) == FALSE)
    {
      /* wait long enough if invoked outside of main function context */
      CANSM_NW_INFO_TIMER(nw) = invokedInMainFunction ?
                                CANSM_BOR_TIME_TX_ENSURED(nw) :
                                (CANSM_BOR_TIME_TX_ENSURED(nw) + 1U);
    }
#else /* CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON */
    TS_PARAM_UNUSED(nw);
    TS_PARAM_UNUSED(invokedInMainFunction);
#endif /* CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON */
  }
  CANSM_EXIT_CRITICAL_SECTION();

  ComM_BusSM_ModeIndication(CANSM_NW_HANDLE_FROM_IDX(nw), &CanSM_CommFullCommunication);

  DBG_CANSM_DO_T_SICO_FUCO_EXIT(nw,invokedInMainFunction);
}



/* bus-off recovery state machine */

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_FUCO_HANDLE_BUS_OFF(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_DO_T_FUCO_HANDLE_BUS_OFF_ENTRY(nw,nextTransition);

  if (CANSM_NW_INFO_BOR_COUNTER(nw) != 0xFFU)
  {
    CANSM_NW_INFO_BOR_COUNTER(nw)++;
  }

  BSWM_CANSM_CURRENTSTATE(CANSM_NW_HANDLE_FROM_IDX(nw), CANSM_BSWM_BUS_OFF);

#if (CANSM_PROD_ERR_HANDLING_BUS_OFF == TS_PROD_ERR_REP_TO_DEM)
    /* Deviation MISRA-3 */
    CANSM_REPORT_DEM_BUS_OFF_FAILED(nw);
#elif (CANSM_PROD_ERR_HANDLING_BUS_OFF == TS_PROD_ERR_REP_TO_DET)
    CANSM_DET_WITH_INSTANCEID(
        CANSM_NW_HANDLE_FROM_IDX(nw),
        CANSM_SID_MAINFUNCTION,
        CANSM_E_DEMTODET_BUS_OFF
    );
#endif /* CANSM_PROD_ERR_HANDLING_BUS_OFF == TS_PROD_ERR_REP_TO_DEM */

  /* contrary to SWS, set PDU mode now to avoid transmission after controller restart */
  CanSM_SetPduModes(nw, CANIF_SET_TX_OFFLINE);

  /* middle critical section */
  CANSM_ENTER_CRITICAL_SECTION();
  {
    /* make bus-off recovery visible to CanSM_RequestComMode by updating internal state; reset
     * bus-off flag */
    uint8 buf = CANSM_NO_BUS_OFF;
    TS_AtomicAssign8(CANSM_NW_INFO_BUSOFF(nw), buf);

    DBG_CANSM_INTERNALSTATE_GRP(nw, (CANSM_NW_INFO_INTERNALSTATE(nw)), (CANSM_S_FUCO_RESTART_CC));
    CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_FUCO_RESTART_CC;

    if (CANSM_NW_INFO_BOR_COUNTER(nw) < CANSM_BOR_COUNTER_L1_TO_L2(nw))
    {
      CANSM_NW_INFO_TIMER(nw) = CANSM_BOR_TIME_L1(nw);
    }
    else
    {
      CANSM_NW_INFO_TIMER(nw) = CANSM_BOR_TIME_L2(nw);
    }
  }
  CANSM_EXIT_CRITICAL_SECTION();

  CanSM_ClearCtrlModeIndAndSetModes(nw, CANIF_CS_STARTED, &allModeIndicationsReceived);

  if (allModeIndicationsReceived == TRUE)
  {
    *nextTransition = CANSM_T_FUCO_TX_OFF;
  }

  DBG_CANSM_DO_T_FUCO_HANDLE_BUS_OFF_EXIT(nw,nextTransition);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_FUCO_TX_OFF(
  const CanSM_NetworkIndexType nw
)
{

  DBG_CANSM_DO_T_FUCO_TX_OFF_ENTRY(nw);
  CANSM_ENTER_CRITICAL_SECTION();
  {
    uint8 buf = CANSM_SILENT_COMMUNICATION;
    TS_AtomicAssign8(CANSM_NW_INFO_STATE(nw), buf);

    DBG_CANSM_INTERNALSTATE_GRP(nw, (CANSM_NW_INFO_INTERNALSTATE(nw)), (CANSM_S_FUCO_TX_OFF));
    CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_FUCO_TX_OFF;
  }
  CANSM_EXIT_CRITICAL_SECTION();

  ComM_BusSM_ModeIndication(CANSM_NW_HANDLE_FROM_IDX(nw), &CanSM_CommSilentCommunication);

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  DBG_CANSM_DO_T_FUCO_TX_OFF_EXIT(nw);
}

STATIC FUNC(void, CANSM_CODE) CanSM_Do_T_FUCO_TX_ON(
  const CanSM_NetworkIndexType nw
)
{

  DBG_CANSM_DO_T_FUCO_TX_ON_ENTRY(nw);
  CanSM_SetPduModes(nw, CANIF_SET_ONLINE);

  CANSM_ENTER_CRITICAL_SECTION();
  {
    uint8 buf = CANSM_FULL_COMMUNICATION;
    TS_AtomicAssign8(CANSM_NW_INFO_STATE(nw), buf);

    DBG_CANSM_INTERNALSTATE_GRP(nw, (CANSM_NW_INFO_INTERNALSTATE(nw)), (CANSM_S_FUCO_BUS_OFF_CHECK));
    CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_FUCO_BUS_OFF_CHECK;

#if (CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON)
    /* Deviation MISRA-3 */
    if (CANSM_BOR_TX_CONFIRMATION_POLLING(nw) == FALSE)
    {
      CANSM_NW_INFO_TIMER(nw) = CANSM_BOR_TIME_TX_ENSURED(nw);
    }
#endif /* CANSM_USE_BOR_TIME_TX_ENSURED == STD_ON */
  }
  CANSM_EXIT_CRITICAL_SECTION();

  BSWM_CANSM_CURRENTSTATE(CANSM_NW_HANDLE_FROM_IDX(nw), CANSM_BSWM_FULL_COMMUNICATION);
  ComM_BusSM_ModeIndication(CANSM_NW_HANDLE_FROM_IDX(nw), &CanSM_CommFullCommunication);

  DBG_CANSM_DO_T_FUCO_TX_ON_EXIT(nw);
}



STATIC FUNC(void, CANSM_CODE) CanSM_Do_TRY_T_FUCO_BUS_OFF_PASSIVE(
  const CanSM_NetworkIndexType nw
)
{
  boolean stillInFuCo = FALSE;

  DBG_CANSM_DO_TRY_T_FUCO_BUS_OFF_PASSIVE_ENTRY(nw);

  CANSM_ENTER_CRITICAL_SECTION();
  {
    /* check if we did not leave full communication */
    if (CANSM_NW_INFO_INTERNALSTATE(nw) == CANSM_S_FUCO_BUS_OFF_CHECK)
    {
      /* perform T_FUCO_BUS_OFF_PASSIVE inside critical section */

      stillInFuCo = TRUE;
      DBG_CANSM_INTERNALSTATE_GRP(nw, (CANSM_NW_INFO_INTERNALSTATE(nw)), (CANSM_S_FUCO_NO_BUS_OFF));
      CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_FUCO_NO_BUS_OFF;
      CANSM_NW_INFO_BOR_COUNTER(nw) = 0U;
    }
  }
  CANSM_EXIT_CRITICAL_SECTION();

  if (stillInFuCo == TRUE)
  {
#if (CANSM_PROD_ERR_HANDLING_BUS_OFF == TS_PROD_ERR_REP_TO_DEM)
    /* Deviation MISRA-3 */
    CANSM_REPORT_DEM_BUS_OFF_PASSED(nw);
#endif /* CANSM_PROD_ERR_HANDLING_BUS_OFF == TS_PROD_ERR_REP_TO_DEM */
  }

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  DBG_CANSM_DO_TRY_T_FUCO_BUS_OFF_PASSIVE_EXIT(nw);
}



/* CanSM_MainFunctionInternal subroutines */

STATIC FUNC(void, CANSM_CODE) CanSM_MainFunctionCheckModeIndications
(
  const CanSM_NetworkIndexType nw,
  const uint8 internalState,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{

  DBG_CANSM_MAINFUNCTIONCHECKMODEINDICATIONS_ENTRY(nw,internalState,nextTransition);
  switch (internalState)
  {
    /* states when preparing NOCO */

#if (CANSM_USE_TRANSCEIVER == STD_ON)
    case CANSM_S_RNOCO_CAN_TRCV_NORMAL:
      if (CanSM_CheckTrcvModeIndication(nw, CANTRCV_TRCVMODE_NORMAL) == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_TRCV_NORMAL;
      }
      break;
    case CANSM_S_RNOCO_CAN_TRCV_STANDBY:
      if (CanSM_CheckTrcvModeIndication(nw, CANTRCV_TRCVMODE_STANDBY) == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_FINAL;
      }
      break;
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

    case CANSM_S_RNOCO_CAN_CC_STOPPED:
      if (CanSM_CheckCtrlModeIndications(nw, CANIF_CS_STOPPED) == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_CC_STOPPED;
      }
      break;
    case CANSM_S_RNOCO_CAN_CC_SLEEP:
      if (CanSM_CheckCtrlModeIndications(nw, CANIF_CS_SLEEP) == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_CC_SLEEP;
      }
      break;

    /* states when preparing NOCO with partial networking */
#if (CANSM_PNSUPPORT == STD_ON)
    case CANSM_S_PN_CLEAR_WUF:
      if (CANSM_NW_INFO_TRCVCLEARWUFINDICATION(nw) == TRUE)
      {
        *nextTransition = CANSM_T_PN_CLEAR_WUF_INDICATED;
      }
      break;
    case CANSM_S_PN_CC_STOPPED:
      if (CanSM_CheckCtrlModeIndications(nw, CANIF_CS_STOPPED) == TRUE)
      {
        *nextTransition = CANSM_T_PN_CC_STOPPED_INDICATED;
      }
      break;
    case CANSM_S_PN_TRCV_NORMAL:
      if (CanSM_CheckTrcvModeIndication(nw, CANTRCV_TRCVMODE_NORMAL) == TRUE)
      {
        *nextTransition = CANSM_T_PN_TRCV_NORMAL_INDICATED;
      }
      break;
    case CANSM_S_PN_TRCV_STANDBY:
      if (CanSM_CheckTrcvModeIndication(nw, CANTRCV_TRCVMODE_STANDBY) == TRUE)
      {
        *nextTransition = CANSM_T_PN_TRCV_STANDBY_INDICATED;
      }
      break;
    case CANSM_S_PN_CC_SLEEP:
      if (CanSM_CheckCtrlModeIndications(nw, CANIF_CS_SLEEP) == TRUE)
      {
        *nextTransition = CANSM_T_PN_CC_SLEEP_INDICATED;
      }
      break;
    case CANSM_S_PN_CHECK_WFLAG_IN_CC_SLEEP:
      if (CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION(nw) == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_FINAL;
      }
      break;
    case CANSM_S_PN_CHECK_WFLAG_IN_NOT_CC_SLEEP:
      if (CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION(nw) == TRUE)
      {
        *nextTransition = CANSM_T_PN_DEINIT;
      }
      break;
#endif /* CANSM_PNSUPPORT == STD_ON */

    /* states when preparing FUCO */

#if (CANSM_USE_TRANSCEIVER == STD_ON)
    case CANSM_S_RFUCO_CAN_TRCV_NORMAL:
      if (CanSM_CheckTrcvModeIndication(nw, CANTRCV_TRCVMODE_NORMAL) == TRUE)
      {
        *nextTransition = CANSM_T_RFUCO_TRCV_NORMAL;
      }
      break;
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

    case CANSM_S_RFUCO_CAN_CC_STOPPED:
      if (CanSM_CheckCtrlModeIndications(nw, CANIF_CS_STOPPED) == TRUE)
      {
        *nextTransition = CANSM_T_RFUCO_CC_STOPPED;
      }
      break;
    case CANSM_S_RFUCO_CAN_CC_STARTED:
      if (CanSM_CheckCtrlModeIndications(nw, CANIF_CS_STARTED) == TRUE)
      {
        *nextTransition = CANSM_T_RFUCO_CC_STARTED;
      }
      break;

    /* BOR */

    case CANSM_S_FUCO_RESTART_CC:
      if (CanSM_CheckCtrlModeIndications(nw, CANIF_CS_STARTED) == TRUE)
      {
        *nextTransition = CANSM_T_FUCO_TX_OFF;
      }
      break;

    /* CHECK: NOPARSE */
    default:
      CANSM_UNREACHABLE_CODE_ASSERT(CANSM_SID_MAINFUNCTION);
      break;
    /* CHECK: PARSE */
  }

  DBG_CANSM_MAINFUNCTIONCHECKMODEINDICATIONS_EXIT(nw,internalState,nextTransition);
}



STATIC FUNC(void, CANSM_CODE) CanSM_MainFunctionRepeatModeRequests
(
  const CanSM_NetworkIndexType nw,
  const uint8 internalState,
  CONSTP2VAR(CanSM_TransitionType, AUTOMATIC, AUTOMATIC) nextTransition
)
{
  /* set by helper functions which request ctrl/trcv mode, initialized to prevent compiler
   * warning */
  boolean allModeIndicationsReceived = FALSE;

  DBG_CANSM_MAINFUNCTIONREPEATMODEREQUESTS_ENTRY(nw,internalState,nextTransition);

  switch (internalState)
  {
    /* preparing NOCO */

#if (CANSM_USE_TRANSCEIVER == STD_ON)
    case CANSM_S_RNOCO_CAN_TRCV_NORMAL:
      CanSM_SetTrcvMode(nw, CANTRCV_TRCVMODE_NORMAL, &allModeIndicationsReceived);

      /* if we get the mode indication immediately, transition to next state */
      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_TRCV_NORMAL;
      }
      break;
    case CANSM_S_RNOCO_CAN_TRCV_STANDBY:
      CanSM_SetTrcvMode(nw, CANTRCV_TRCVMODE_STANDBY, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_FINAL;
      }
      break;
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

    case CANSM_S_RNOCO_CAN_CC_STOPPED:
      CanSM_SetCtrlModes(nw, CANIF_CS_STOPPED, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_CC_STOPPED;
      }
      break;
    case CANSM_S_RNOCO_CAN_CC_SLEEP:
      CanSM_SetCtrlModes(nw, CANIF_CS_SLEEP, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_CC_SLEEP;
      }
      break;

    /* preparing NOCO with partial networking */

#if (CANSM_PNSUPPORT == STD_ON)
    case CANSM_S_PN_CLEAR_WUF:
      CanSM_ClearTrcvWufFlag(nw, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_PN_CLEAR_WUF_INDICATED;
      }
      break;
    case CANSM_S_PN_CC_STOPPED:
      CanSM_SetCtrlModes(nw, CANIF_CS_STOPPED, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_PN_CC_STOPPED_INDICATED;
      }
      break;
    case CANSM_S_PN_TRCV_NORMAL:
      CanSM_SetTrcvMode(nw, CANTRCV_TRCVMODE_NORMAL, &allModeIndicationsReceived);

      /* if we get the mode indication immediately, transition to next state */
      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_PN_TRCV_NORMAL_INDICATED;
      }
      break;
    case CANSM_S_PN_TRCV_STANDBY:
      CanSM_SetTrcvMode(nw, CANTRCV_TRCVMODE_STANDBY, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_PN_TRCV_STANDBY_INDICATED;
      }
      break;
    case CANSM_S_PN_CC_SLEEP:
      {
        *nextTransition = CANSM_T_PN_CC_SLEEP_TIMEOUT;
      }
      break;
    case CANSM_S_PN_CHECK_WFLAG_IN_CC_SLEEP:
      CanSM_CheckTrcvWakeFlag(nw, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_RNOCO_FINAL;
      }
      break;
    case CANSM_S_PN_CHECK_WFLAG_IN_NOT_CC_SLEEP:
      CanSM_CheckTrcvWakeFlag(nw, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_PN_DEINIT;
      }
      break;
#endif /* CANSM_PNSUPPORT == STD_ON */

    /* preparing FUCO */

#if (CANSM_USE_TRANSCEIVER == STD_ON)
    case CANSM_S_RFUCO_CAN_TRCV_NORMAL:
      CanSM_SetTrcvMode(nw, CANTRCV_TRCVMODE_NORMAL, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_RFUCO_TRCV_NORMAL;
      }
      break;
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

    case CANSM_S_RFUCO_CAN_CC_STOPPED:
      CanSM_SetCtrlModes(nw, CANIF_CS_STOPPED, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_RFUCO_CC_STOPPED;
      }
      break;
    case CANSM_S_RFUCO_CAN_CC_STARTED:
      CanSM_SetCtrlModes(nw, CANIF_CS_STARTED, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_RFUCO_CC_STARTED;
      }
      break;

    /* BOR */

    case CANSM_S_FUCO_RESTART_CC:
      CanSM_SetCtrlModes(nw, CANIF_CS_STARTED, &allModeIndicationsReceived);

      if (allModeIndicationsReceived == TRUE)
      {
        *nextTransition = CANSM_T_FUCO_TX_OFF;
      }
      break;

    /* CHECK: NOPARSE */
    default:
      CANSM_UNREACHABLE_CODE_ASSERT(CANSM_SID_MAINFUNCTION);
      break;
    /* CHECK: PARSE */
  }

  DBG_CANSM_MAINFUNCTIONREPEATMODEREQUESTS_EXIT(nw,internalState,nextTransition);
}



/* default trailing critical section */

STATIC FUNC(void, CANSM_CODE) CanSM_DefaultTrailingCriticalSection(
  const CanSM_NetworkIndexType nw,
  const uint8 newInternalState)
{

  DBG_CANSM_DEFAULTTRAILINGCRITICALSECTION_ENTRY(nw,newInternalState);
  CANSM_ENTER_CRITICAL_SECTION();
  DBG_CANSM_INTERNALSTATE_GRP(nw, (CANSM_NW_INFO_INTERNALSTATE(nw)), (newInternalState));
  CANSM_NW_INFO_INTERNALSTATE(nw) = newInternalState;
  CANSM_EXIT_CRITICAL_SECTION();

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1 */

  DBG_CANSM_DEFAULTTRAILINGCRITICALSECTION_EXIT(nw,newInternalState);
}



/* controller helper functions */

STATIC FUNC(void, CANSM_CODE) CanSM_SetPduModes(
  const CanSM_NetworkIndexType nw,
  const CanIf_PduSetModeType pduModeRequest
)
{
  uint8_least i;
  uint8_least ctrl= CANSM_NW_CONFIG_CTRL_START(nw);

  DBG_CANSM_SETPDUMODES_ENTRY(nw,pduModeRequest);

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  for ( i=0U; i < CANSM_NW_CONFIG_CTRL_NUM(nw); i++ )
  {
    /* Deviation MISRA-1 */
    (void) CanIf_SetPduMode(CANSM_NW_CONFIG_CTRL(ctrl), pduModeRequest);

    ctrl++;
  }

  DBG_CANSM_SETPDUMODES_EXIT(nw,pduModeRequest);
}

STATIC FUNC(void, CANSM_CODE) CanSM_ClearCtrlModeIndAndSetModes(
  const CanSM_NetworkIndexType nw,
  const CanIf_ControllerModeType ctrlMode,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) allModeIndicationsReceived
)
{
  uint8_least i;
  uint8_least ctrl= CANSM_NW_CONFIG_CTRL_START(nw);

  DBG_CANSM_CLEARCTRLMODEINDANDSETMODES_ENTRY(nw,ctrlMode,allModeIndicationsReceived);

  for ( i=0U; i < CANSM_NW_CONFIG_CTRL_NUM(nw); i++ )
  {
    uint8 buf = CANSM_CTRLMODETYPE_RESET;
    TS_AtomicAssign8(CanSM_CtrlModeIndication[CANSM_NW_CONFIG_CTRL(ctrl)], buf);

    ctrl++;
  }

  CanSM_SetCtrlModes(nw, ctrlMode, allModeIndicationsReceived);

  DBG_CANSM_CLEARCTRLMODEINDANDSETMODES_EXIT(nw,ctrlMode,allModeIndicationsReceived);
}

#if (CANSM_PNSUPPORT == STD_ON)
STATIC FUNC(CanSM_TransitionType, CANSM_CODE) CanSM_HandleTxTimeoutException
(
  const CanSM_NetworkIndexType nw,
  const uint8 reqState,
  const uint8 internalState
)
{
  /* by default, don't trigger transition to another state */
  CanSM_TransitionType nextTransition = CANSM_T_NONE;

  DBG_CANSM_HANDLETXTIMEOUTEXCEPTION_ENTRY(nw,reqState,internalState);

  /* Precondition: There must be an active recovery from TxTimeoutException */
  CANSM_PRECONDITION_ASSERT(reqState != CANSM_NO_STATE_REQ, CANSM_SID_MAINFUNCTION);

  if ( internalState == CANSM_S_NOCO )
  {
    /* The TxTimeoutException recovery reached state NO_COMMUNICATION ...  */
    nextTransition =  CANSM_T_RFUCO_INITIAL;

    /* ... in case we need to recover to FULL_COMMUNICATION delete the recovery
     * indication now.
     * But if recovering to SILENT_COM this is done via FULL_COMMUNICATION.
     * This means, that this is not(!) the final transition, therefore the
     * recovery indicatin stay valid.
     */
    if ( reqState == CANSM_REQ_STATE_FULL_COM )
    {
      CANSM_NW_INFO_REQ_STATE( nw ) = CANSM_NO_STATE_REQ;
    }
  }
  else if ( (internalState == CANSM_S_SICO) || (internalState == CANSM_S_FUCO_NO_BUS_OFF) )
  {
    /* There is no ongoing transition
     * --> begin with recovery in state NO_COMMUNICATION.
     */
    nextTransition =  CANSM_T_RNOCO_INITIAL;
  }
  else if ( internalState == CANSM_S_FUCO_BUS_OFF_CHECK )
  {
    /* We reached "initial" substate of FULL_COMMUNICATION, but the
     * TxTimeoutException recovery indication is still set.
     * There are two possibilities for this:
     * a) CanSM_TxTimeoutException was called during ongoing bus-off recovery.
     *    --> begin with recovery in state NO_COMMUNICATION.
     * b) Recovery shall be done to state SILENT_COMMUNICATION.
     *    --> initiate the final transition and delete the recovery indication now.
     */
    if ( reqState == CANSM_REQ_STATE_FULL_COM )
    {
      nextTransition =  CANSM_T_RNOCO_INITIAL;
    }
    else
    {
      nextTransition = CANSM_T_FUCO_SICO;
      CANSM_NW_INFO_REQ_STATE( nw ) = CANSM_NO_STATE_REQ;
      /* Exception: the internal state in not set in case of a transition to 'silent
       * communication to prevent race-conditions between CanSM_RequestComMode and
       * bus-off recovery.
       */
      CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_SICO;
    }
  }
  else
  {
    /* TxTimeoutException recovery indication set, but we are in no (sub-state) to
     * start with recovery (e.g. there is an ongoing bus-off recovery or a ongoing
     * transition from NO_COMMUNICATION to FULL_COMMUNICATION.
     *  --> Don't signalize any transition (cause by TxTimeoutException). Let the
     *      ongoing transition finishing first.
     */
  }

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  DBG_CANSM_HANDLETXTIMEOUTEXCEPTION_EXIT(nextTransition,nw,reqState,internalState);
  return nextTransition;
}
#endif /* CANSM_PNSUPPORT == STD_ON */

STATIC FUNC(boolean, CANSM_CODE) CanSM_CheckCtrlModeIndications(
  const CanSM_NetworkIndexType nw,
  const CanIf_ControllerModeType ctrlMode
)
{
  boolean result = TRUE;
  uint8_least i;
  uint8_least ctrl= CANSM_NW_CONFIG_CTRL_START(nw);

  DBG_CANSM_CHECKCTRLMODEINDICATIONS_ENTRY(nw,ctrlMode);

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  for ( i=0U; i < CANSM_NW_CONFIG_CTRL_NUM(nw); i++ )
  {
    uint8 buf;
    TS_AtomicAssign8(buf, CanSM_CtrlModeIndication[CANSM_NW_CONFIG_CTRL(ctrl)]);

    if (buf != CanSM_ControllerModeTypeToUint8(ctrlMode))
    {
      result = FALSE;
      break;
    }

    ctrl++;
  }


  DBG_CANSM_CHECKCTRLMODEINDICATIONS_EXIT(result,nw,ctrlMode);
  return result;
}

STATIC FUNC(void, CANSM_CODE) CanSM_SetCtrlModes(
  const CanSM_NetworkIndexType nw,
  const CanIf_ControllerModeType ctrlMode,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) allModeIndicationsReceived
)
{
  uint8_least i;
  uint8_least ctrl= CANSM_NW_CONFIG_CTRL_START(nw);

  DBG_CANSM_SETCTRLMODES_ENTRY(nw,ctrlMode,allModeIndicationsReceived);

  for ( i=0U; i < CANSM_NW_CONFIG_CTRL_NUM(nw); i++ )
  {
    uint8 buf;
    TS_AtomicAssign8(buf, CanSM_CtrlModeIndication[CANSM_NW_CONFIG_CTRL(ctrl)]);

    if (buf != CanSM_ControllerModeTypeToUint8(ctrlMode))
    {
      /* on error, retry after mode indication timeout */
      /* Deviation MISRA-1 */
      (void)CanIf_SetControllerMode(CANSM_NW_CONFIG_CTRL(ctrl), ctrlMode);
    }

    ctrl++;
  }

  *allModeIndicationsReceived = CanSM_CheckCtrlModeIndications(nw, ctrlMode);

  DBG_CANSM_SETCTRLMODES_EXIT(nw,ctrlMode,allModeIndicationsReceived);
}

STATIC FUNC(uint8, CANSM_CODE) CanSM_ControllerModeTypeToUint8(
  const CanIf_ControllerModeType ctrlMode
)
{
  uint8 result;

  DBG_CANSM_CONTROLLERMODETYPETOUINT8_ENTRY(ctrlMode);

  switch (ctrlMode)
  {
    case CANIF_CS_STOPPED:
      result = CANSM_CTRLMODETYPE_STOPPED;
      break;
    case CANIF_CS_SLEEP:
      result = CANSM_CTRLMODETYPE_SLEEP;
      break;
    case CANIF_CS_STARTED:
      result = CANSM_CTRLMODETYPE_STARTED;
      break;
    /* CHECK: NOPARSE */
    default:
      result = CANSM_CTRLMODETYPE_RESET;
      CANSM_UNREACHABLE_CODE_ASSERT(CANSM_INTERNAL_API_ID);
      break;
    /* CHECK: PARSE */
  }


  DBG_CANSM_CONTROLLERMODETYPETOUINT8_EXIT(result,ctrlMode);
  return result;
}

#if (CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE == STD_ON)
STATIC FUNC(boolean, CANSM_CODE) CanSM_CheckCanIfGetTxConfirmationStates(
  const CanSM_NetworkIndexType nw
)
{
  boolean result = TRUE;
  uint8_least i;
  uint8_least ctrl= CANSM_NW_CONFIG_CTRL_START(nw);

  DBG_CANSM_CHECKCANIFGETTXCONFIRMATIONSTATES_ENTRY(nw);

  for ( i=0U; i < CANSM_NW_CONFIG_CTRL_NUM(nw); i++ )
  {
    if (CanIf_GetTxConfirmationState(CANSM_NW_CONFIG_CTRL(ctrl)) != CANIF_TX_RX_NOTIFICATION)
    {
      result = FALSE;
      break;
    }

    ctrl++;
  }

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */


  DBG_CANSM_CHECKCANIFGETTXCONFIRMATIONSTATES_EXIT(result,nw);
  return result;
}
#endif /* CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE == STD_ON */





/* transceiver helper functions */

#if (CANSM_TRCV_RESOURCES == STD_ON)

STATIC FUNC(void, CANSM_CODE) CanSM_ClearTrcvModeIndAndSetMode(
  const CanSM_NetworkIndexType nw,
  const CanTrcv_TrcvModeType trcvMode,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) modeIndicationReceived
)
{
  uint8 buf = CANSM_TRCVMODETYPE_RESET;

  DBG_CANSM_CLEARTRCVMODEINDANDSETMODE_ENTRY(nw,trcvMode,modeIndicationReceived);
  TS_AtomicAssign8(CANSM_NW_INFO_TRCVMODEINDICATION(nw), buf);

  CanSM_SetTrcvMode(nw, trcvMode, modeIndicationReceived);

  DBG_CANSM_CLEARTRCVMODEINDANDSETMODE_EXIT(nw,trcvMode,modeIndicationReceived);
}

STATIC FUNC(boolean, CANSM_CODE) CanSM_CheckTrcvModeIndication(
  const CanSM_NetworkIndexType nw,
  const CanTrcv_TrcvModeType trcvMode
)
{
  boolean result = FALSE;
  uint8 buf;

  DBG_CANSM_CHECKTRCVMODEINDICATION_ENTRY(nw,trcvMode);

#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  TS_AtomicAssign8(buf, CANSM_NW_INFO_TRCVMODEINDICATION(nw));

  if (buf == CanSM_TrcvModeTypeToUint8(trcvMode))
  {
    result = TRUE;
  }


  DBG_CANSM_CHECKTRCVMODEINDICATION_EXIT(result,nw,trcvMode);
  return result;
}

STATIC FUNC(void, CANSM_CODE) CanSM_SetTrcvMode(
  const CanSM_NetworkIndexType nw,
  const CanTrcv_TrcvModeType trcvMode,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) modeIndicationReceived
)
{
  DBG_CANSM_SETTRCVMODE_ENTRY(nw,trcvMode,modeIndicationReceived);

  /* on error, retry after mode indication timeout */
  /* Deviation MISRA-1 */
  (void)CanIf_SetTrcvMode(CANSM_NW_CONFIG_TRCV_ID(nw), trcvMode);

  *modeIndicationReceived = CanSM_CheckTrcvModeIndication(nw, trcvMode);

  DBG_CANSM_SETTRCVMODE_EXIT(nw,trcvMode,modeIndicationReceived);
}

STATIC FUNC(uint8, CANSM_CODE) CanSM_TrcvModeTypeToUint8(
  const CanTrcv_TrcvModeType trcvMode
)
{
  uint8 result;

  DBG_CANSM_TRCVMODETYPETOUINT8_ENTRY(trcvMode);

  switch (trcvMode)
  {
    case CANTRCV_TRCVMODE_NORMAL:
      result = CANSM_TRCVMODETYPE_NORMAL;
      break;
    case CANTRCV_TRCVMODE_STANDBY:
      result = CANSM_TRCVMODETYPE_STANDBY;
      break;
    /* CHECK: NOPARSE */
    default:
      result = CANSM_TRCVMODETYPE_RESET;
      CANSM_UNREACHABLE_CODE_ASSERT(CANSM_INTERNAL_API_ID);
      break;
    /* CHECK: PARSE */
  }


  DBG_CANSM_TRCVMODETYPETOUINT8_EXIT(result,trcvMode);
  return result;
}

#endif /* CANSM_TRCV_RESOURCES == STD_ON */

/* partial networking helper functions */

#if (CANSM_PNSUPPORT == STD_ON)

STATIC FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlag(
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) clearIndicationReceived
)
{
  DBG_CANSM_CLEARTRCVWUFFLAG_ENTRY(nw,clearIndicationReceived);
#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  /* on error, retry after mode indication timeout */
  /* Deviation MISRA-1 */

  (void)CanIf_ClearTrcvWufFlag(CANSM_NW_CONFIG_TRCV_ID(nw));

  TS_AtomicAssign8(*clearIndicationReceived, CANSM_NW_INFO_TRCVCLEARWUFINDICATION(nw));

  DBG_CANSM_CLEARTRCVWUFFLAG_EXIT(nw,clearIndicationReceived);
}


STATIC FUNC(void, CANSM_CODE) CanSM_CheckTrcvWakeFlag (
  const CanSM_NetworkIndexType nw,
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) checkIndicationReceived
)
{
  DBG_CANSM_CHECKTRCVWAKEFLAG_ENTRY(nw,checkIndicationReceived);
#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(nw);
#endif /* CANSM_NETWORKS_NUM == 1U */

  /* on error, retry after mode indication timeout */
  /* Deviation MISRA-1 */

  (void)CanIf_CheckTrcvWakeFlag(CANSM_NW_CONFIG_TRCV_ID(nw));

  TS_AtomicAssign8(*checkIndicationReceived, CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION(nw));

  DBG_CANSM_CHECKTRCVWAKEFLAG_EXIT(nw,checkIndicationReceived);
}

#endif /* CANSM_PNSUPPORT == STD_ON */



#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

/*==================[end of file]===========================================*/
