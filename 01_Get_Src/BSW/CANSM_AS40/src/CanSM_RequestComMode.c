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

/*==================[inclusions]============================================*/

#include <CanSM_Trace.h>
#include <TSAutosar.h>              /* EB specific standard types */
#include <ComStack_Types.h>         /* AUTOSAR communication stack types */
#include <TSAtomic_Assign.h>        /* Atomic assignment macros */

#include <CanSM_Cfg.h>              /* DET configuration */
#include <CanSM_ComM.h>             /* Module ComM API */
#include <CanSM_Internal.h>         /* Module private API */
#include <CanSM_TxTimeoutException.h>  /* API declaration */

#include <ComM.h>                   /* Communication Manager types */
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

/**
 * Subroutine of CanSM_RequestComMode.
 *
 * \param[in] nw Network index
 * \param[in] ComM_Mode CanSM_RequestComMode parameter
 *
 * \return Std_ReturnType
 * \retval E_OK Accept request
 * \retval E_NOT_OK Deny request
 */
STATIC FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComModeInternal (
  const CanSM_NetworkIndexType nw,
  const ComM_ModeType ComM_Mode
);

/**
 * Processes mode changes from state CANSM_NO_COMMUNICATION
 *
 * \param[in] nw Network index
 * \param[in] modeRequested Requested communication mode
 */
STATIC FUNC(void, CANSM_CODE) CanSM_StateNoCommunication (
    const CanSM_NetworkIndexType nw,
    const ComM_ModeType modeRequested
);

/**
 * Processes mode changes from state CANSM_SILENT_COMMUNICATION
 *
 * \param[in] nw Network index
 * \param[in] modeRequested Requested communication mode
 */
STATIC FUNC(void, CANSM_CODE) CanSM_StateSilentCommunication(
    const CanSM_NetworkIndexType nw,
    const ComM_ModeType modeRequested
);

/**
 * Processes mode changes from state CANSM_FULL_COMMUNICATION
 *
 * \param[in] nw Network index
 * \param[in] modeRequested Requested communication mode
 */
STATIC FUNC(void, CANSM_CODE) CanSM_StateFullCommunication(
    const CanSM_NetworkIndexType nw,
    const ComM_ModeType modeRequested
);

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_START_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode (
  NetworkHandleType  network,
  ComM_ModeType  ComM_Mode
)
{
  Std_ReturnType retval = E_NOT_OK;

  DBG_CANSM_REQUESTCOMMODE_ENTRY(network,ComM_Mode);

  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* CANSM184 */
    CANSM_DET(CANSM_SID_REQUESTCOMMODE, CANSM_E_UNINIT);
#endif
  }
  /* CANSM369 */
  else if ( ! (CANSM_NW_HANDLE_IS_VALID(network)) )
  {
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* CANSM183 */
    CANSM_DET(CANSM_SID_REQUESTCOMMODE, CANSM_E_INVALID_NETWORK_HANDLE);
#endif
  }
  else if (
            (ComM_Mode != COMM_NO_COMMUNICATION)
            &&
            (
              (ComM_Mode != COMM_SILENT_COMMUNICATION)
              &&
              (ComM_Mode != COMM_FULL_COMMUNICATION)
            )
          )
  {
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    CANSM_DET(CANSM_SID_REQUESTCOMMODE, CANSM_E_INVALID_COMM_REQUEST);
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
  }
  else
  {
    CanSM_NetworkIndexType nw = CANSM_NW_IDX_FROM_HANDLE(network);
    retval = CanSM_RequestComModeInternal(nw, ComM_Mode);
  }


  DBG_CANSM_REQUESTCOMMODE_EXIT(retval,network,ComM_Mode);
  return retval;
} /* CanSM_RequestComMode */


#if (CANSM_PNSUPPORT == STD_ON)
FUNC(void, CANSM_CODE) CanSM_TxTimeoutException
(
  NetworkHandleType Channel
)
{
  DBG_CANSM_TXTIMEOUTEXCEPTION_ENTRY(Channel);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
    /* CANSM411 */
    CANSM_DET(CANSM_SID_TXTIMEOUTEXCEPTION, CANSM_E_UNINIT);
  }
  else if ( ! (CANSM_NW_HANDLE_IS_VALID(Channel)) )
  {
    /* CANSM412 */
    CANSM_DET(CANSM_SID_TXTIMEOUTEXCEPTION, CANSM_E_INVALID_NETWORK_HANDLE);
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */

  {
    uint8 reqState;
    uint8 internalState;
    CanSM_NetworkIndexType nw = CANSM_NW_IDX_FROM_HANDLE(Channel);

    /* secure decision about necessary transitions against Mainfunction */
    CANSM_ENTER_CRITICAL_SECTION();
    {
      reqState = CANSM_NW_INFO_REQ_STATE( nw );
      internalState = CANSM_NW_INFO_INTERNALSTATE( nw );

      if ( reqState == CANSM_NO_STATE_REQ )
      {
        /* only accept the request if no old ongoing recovery is in progress! */

          switch ( internalState )
          {
#if (CANSM_USE_TRANSCEIVER == STD_ON)
            case CANSM_S_RFUCO_CAN_TRCV_NORMAL:
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */
            case CANSM_S_RFUCO_CAN_CC_STOPPED:
            case CANSM_S_RFUCO_CAN_CC_STARTED:
            case CANSM_S_FUCO_BUS_OFF_CHECK:
            case CANSM_S_FUCO_NO_BUS_OFF:
            case CANSM_S_FUCO_RESTART_CC:
            case CANSM_S_FUCO_TX_OFF:
              /* The CanSM state machine is in some substate of state FULL_COMMUNICATION
               * or performing a transition towards FULL_COMMUNICATION.
               * Thus after recovery try to reach state FULL_COMMUNICATION again.
               */
              reqState = CANSM_REQ_STATE_FULL_COM;
              break;
            case CANSM_S_SICO:
              /* The CanSM state machine is in state SILENT_COMMUNICATION.
               * Thus after recovery try to reach state SILENT_COMMUNICATION again.
               */
              reqState = CANSM_REQ_STATE_SILENT_COM;
              break;
            default:
              /* We are already in state NO_COMMUNICATION or performing a state
               * transition towards.
               * Thus there is no reason for recovery and nothing shall be done. */
              break;
          }

          /* store the state to recover after performing a transition to NO_COMMUNICATION. */
          CANSM_NW_INFO_REQ_STATE( nw ) = reqState;
      }
      /* else: old recovery in progress: (silently) reject request */

    }
    CANSM_EXIT_CRITICAL_SECTION();

#if (CANSM_NETWORKS_NUM == 1U)
    TS_PARAM_UNUSED(nw);
#if (CANSM_DEV_ERROR_DETECT == STD_OFF)
    TS_PARAM_UNUSED(Channel);
#endif /* CANSM_DEV_ERROR_DETECT == STD_OFF */
#endif /* CANSM_NETWORKS_NUM == 1U */

  }

  DBG_CANSM_TXTIMEOUTEXCEPTION_EXIT(Channel);

} /* CanSM_TxTimeoutException */
#endif /* CANSM_PNSUPPORT == STD_ON */


#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif  /* TS_MERGED_COMPILE */

/*==================[internal function definitions]=========================*/

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_START_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

STATIC FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComModeInternal (
  const CanSM_NetworkIndexType nw,
  const ComM_ModeType ComM_Mode
)
{
  Std_ReturnType retval = E_NOT_OK;

  /* by default, don't try to change mode */
  boolean tryRequest = FALSE;

  /* caches CANSM_NW_INFO_STATE */
  uint8 nwState;
  /* caches CANSM_NW_INFO_INTERNALSTATE */
  uint8 internalState;

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  /* saves Det condition detected in critical section */
  uint8 detErrorId = 0U;

#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
  DBG_CANSM_REQUESTCOMMODEINTERNAL_ENTRY(nw,ComM_Mode);

  /* in the first critical section, decide if request shall be accepted
   * (by setting tryRequest)
   *
   * if CanSM_MainFunction could also fire a transition in this state, update
   * CANSM_NW_INFO_INTERNALSTATE in the same critical section
   */
  CANSM_ENTER_CRITICAL_SECTION();
  {
    uint8 busOff;
    nwState = CANSM_NW_INFO_STATE(nw);
    internalState = CANSM_NW_INFO_INTERNALSTATE(nw);

    TS_AtomicAssign8(busOff, CANSM_NW_INFO_BUSOFF(nw));

    if ( CanSM_IsWaitingForModeIndication(internalState) == TRUE )
    {
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
      detErrorId = CANSM_E_WAIT_MODE_INDICATION;
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
    }
#if (CANSM_PNSUPPORT == STD_ON)
    else if ( CANSM_NW_INFO_REQ_STATE( nw ) != CANSM_NO_STATE_REQ )
    {
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
      detErrorId = CANSM_E_TXTIMEOUT_RECOVERY_ACTIVE;
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
    }
#endif /* CANSM_PNSUPPORT == STD_ON */
    else if (
              /* FUCO and bus-off flag set */
              (
                (
                  (internalState == CANSM_S_FUCO_BUS_OFF_CHECK)
                  ||
                  (internalState == CANSM_S_FUCO_NO_BUS_OFF)
                )
                &&
                (busOff == CANSM_BUS_OFF)
              )
              ||
              /* bus-off recovery active */
              (
                (internalState == CANSM_S_FUCO_RESTART_CC)
                ||
                (internalState == CANSM_S_FUCO_TX_OFF)
              )
            )
    {
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
      detErrorId = CANSM_E_BUSOFF_RECOVERY_ACTIVE;
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
      switch (nwState)
      {
        case CANSM_NO_COMMUNICATION:
          if (ComM_Mode == COMM_SILENT_COMMUNICATION)
          {
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
            detErrorId = CANSM_E_INVALID_COMM_REQUEST;
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
          }
          else
          {
            tryRequest = TRUE;
          }
          break;

        case CANSM_SILENT_COMMUNICATION:
          tryRequest = TRUE;
          break;

        case CANSM_FULL_COMMUNICATION:
          if (ComM_Mode != COMM_FULL_COMMUNICATION)
          {
            /* change internal state in this critical section to prevent main function from
             * initiating bus-off recovery if a bus-off happens during transition to silent
             * communication (or no communication done via state silent communication). */
            CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_SICO;
          }
          tryRequest = TRUE;
          break;

        /* CHECK: NOPARSE */
        default:
          CANSM_UNREACHABLE_CODE_ASSERT(CANSM_SID_REQUESTCOMMODE);
          break;
        /* CHECK: PARSE */
      }
    }

  }
  CANSM_EXIT_CRITICAL_SECTION();



#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if (detErrorId != 0U)
  {
    CANSM_DET(CANSM_SID_REQUESTCOMMODE, detErrorId);
  }
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */

  if (tryRequest == TRUE)
  {

    switch (nwState)
    {
      case CANSM_NO_COMMUNICATION:
        CanSM_StateNoCommunication(nw, ComM_Mode);
        break;
      case CANSM_SILENT_COMMUNICATION:
        CanSM_StateSilentCommunication(nw, ComM_Mode);
        break;
      case CANSM_FULL_COMMUNICATION:
        CanSM_StateFullCommunication(nw, ComM_Mode);
        break;
      /* CHECK: NOPARSE */
      default:
        CANSM_UNREACHABLE_CODE_ASSERT(CANSM_SID_REQUESTCOMMODE);
        break;
      /* CHECK: PARSE */
    }

    retval = E_OK;
  }


  DBG_CANSM_REQUESTCOMMODEINTERNAL_EXIT(retval,nw,ComM_Mode);
  return retval;
}

STATIC FUNC(void, CANSM_CODE) CanSM_StateNoCommunication (
  const CanSM_NetworkIndexType nw,
  const ComM_ModeType modeRequested
)
{

  DBG_CANSM_STATENOCOMMUNICATION_ENTRY(nw,modeRequested);
  if (modeRequested != COMM_NO_COMMUNICATION)
  {
    CanSM_DoTransitionSequence(
                                nw,
                                CANSM_T_RFUCO_INITIAL,
                                FALSE
                              );
  }
  /* else: remain in state */

  DBG_CANSM_STATENOCOMMUNICATION_EXIT(nw,modeRequested);
}

STATIC FUNC(void, CANSM_CODE) CanSM_StateSilentCommunication (
    const CanSM_NetworkIndexType nw,
    const ComM_ModeType modeRequested
)
{

  DBG_CANSM_STATESILENTCOMMUNICATION_ENTRY(nw,modeRequested);
  if (modeRequested == COMM_NO_COMMUNICATION)
  {
    CanSM_DoTransitionSequence(
                                nw,
                                CANSM_T_RNOCO_INITIAL,
                                FALSE
                              );
  }
  else if (modeRequested == COMM_SILENT_COMMUNICATION)
  {
    /* remain in state */
  }
  else /* modeRequested == COMM_FULL_COMMUNICATION */
  {
      CanSM_DoTransitionSequence(
                                  nw,
                                  CANSM_T_SICO_FUCO,
                                  FALSE
                                );
  }

  DBG_CANSM_STATESILENTCOMMUNICATION_EXIT(nw,modeRequested);
}

STATIC FUNC(void, CANSM_CODE) CanSM_StateFullCommunication (
    const CanSM_NetworkIndexType nw,
    const ComM_ModeType modeRequested
)
{

  DBG_CANSM_STATEFULLCOMMUNICATION_ENTRY(nw,modeRequested);
  if (modeRequested == COMM_FULL_COMMUNICATION)
  {
    /* remain in state */
  }
  else if(modeRequested == COMM_SILENT_COMMUNICATION)
  {
    CanSM_DoTransitionSequence(
                                nw,
                                CANSM_T_FUCO_SICO,
                                FALSE
                              );
  }
  else /* modeRequested == COMM_NO_COMMUNICATION */
  {
    /* In case COMM_NO_COMMUNICATION is requested:
     * Call to CanSM_RequestComMode counts as trigger T_SILENT_COM_MODE_REQUEST
     * (see Figure 7-6) followed by trigger T_NO_COM_MODE_REQUEST (see Figure 7-1). */
    CanSM_DoTransitionSequence(
                                nw,
                                CANSM_T_FUCO_SICO,
                                FALSE
                              );
    CanSM_DoTransitionSequence(
                                nw,
                                CANSM_T_RNOCO_INITIAL,
                                FALSE
                              );

  }

  DBG_CANSM_STATEFULLCOMMUNICATION_EXIT(nw,modeRequested);
}

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

/*==================[end of file]===========================================*/

