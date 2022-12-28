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


/*
 * * MISRA-C:2004 Deviations:
 *
 *  MISRA-1: Rule 14.7
 *    Reason: Quick abort on failed parameter check
 */

/*==================[inclusions]============================================*/

#include <CanSM_Trace.h>
#include <TSAutosar.h>              /* EB specific standard types */
#include <ComStack_Types.h>         /* AUTOSAR communication stack types */
#include <TSAtomic_Assign.h>        /* Atomic assignment macros */

#include <CanSM_Cfg.h>              /* Module callback API */
#include <CanSM_Cbk.h>              /* Module callback API */
#include <CanSM_Internal.h>         /* Module private API */

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>                    /* Development Error Tracer */
#endif

#if (CANSM_PNSUPPORT == STD_ON)
#include <CanNm.h>                  /* CanNm_ConfirmPnAvailability() */
#endif

/*==================[version check]=========================================*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_START_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

FUNC(void, CANSM_CODE) CanSM_ControllerBusOff (
  uint8 ControllerId
)
{
#if ( (CANSM_NETWORKS_NUM == 1) && (CANSM_DEV_ERROR_DETECT == STD_OFF) )
  TS_PARAM_UNUSED( ControllerId );
#else /* (CANSM_NETWORKS_NUM == 1) && (CANSM_DEV_ERROR_DETECT == STD_OFF) */
      /* if only one network is configured CANSM_NW_INFO_BUSOFF will not use its
         parameter */
  const uint8 nw_index = CANSM_NW_IDX_FROM_CONTROLLER(ControllerId);
#endif /* (CANSM_NETWORKS_NUM == 1) && (CANSM_DEV_ERROR_DETECT == STD_OFF) */

  DBG_CANSM_CONTROLLERBUSOFF_ENTRY(ControllerId);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  /* CANSM190 */
  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
    CANSM_DET(CANSM_SID_CONTROLLERBUSOFF, CANSM_E_UNINIT);
  }
  else if ( nw_index == CANSM_NETWORKS_NUM )
  {
    /* no network found */
    CANSM_DET(CANSM_SID_CONTROLLERBUSOFF, CANSM_E_PARAM_CONTROLLER);
  }
  else
  {
    uint8 internalState;

    TS_AtomicAssign8( internalState, CANSM_NW_INFO_INTERNALSTATE( nw_index ) );

    if( (internalState == CANSM_S_FUCO_RESTART_CC) || (internalState == CANSM_S_FUCO_TX_OFF) )
    {
      /* bus-off recovery still ongoing */
      CANSM_DET(CANSM_SID_CONTROLLERBUSOFF, CANSM_E_BUSOFF_RECOVERY_ACTIVE);
    }
    else if ( (internalState != CANSM_S_FUCO_BUS_OFF_CHECK)
              &&
              (internalState != CANSM_S_FUCO_NO_BUS_OFF)
            )
    {
      /* CanSM not in mode "full communication" */
      CANSM_DET(CANSM_SID_CONTROLLERBUSOFF, CANSM_E_INVALID_BUSOFF_INDICATION);
    }
    else
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
    {

      uint8 buf = CANSM_BUS_OFF;

      /* !LINKSTO dsn.CanSM.CallContext.CanSM_ControllerBusOff,1 */
      TS_AtomicAssign8( CANSM_NW_INFO_BUSOFF( nw_index ), buf );
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  }
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */

  DBG_CANSM_CONTROLLERBUSOFF_EXIT(ControllerId);
}

FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication (
  uint8 ControllerId,
  CanIf_ControllerModeType ControllerMode
)
{

  DBG_CANSM_CONTROLLERMODEINDICATION_ENTRY(ControllerId,ControllerMode);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
    CANSM_DET(CANSM_SID_CONTROLLERMODEINDICATION, CANSM_E_UNINIT);
  }
  else if ( CANSM_NW_IDX_FROM_CONTROLLER(ControllerId) == CANSM_NETWORKS_NUM )
  {
    /* no network found */
    CANSM_DET(CANSM_SID_CONTROLLERMODEINDICATION, CANSM_E_PARAM_CONTROLLER);
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 buf;
    switch (ControllerMode)
    {
      case CANIF_CS_STOPPED:
        buf = CANSM_CTRLMODETYPE_STOPPED;
        break;
      case CANIF_CS_SLEEP:
        buf = CANSM_CTRLMODETYPE_SLEEP;
        break;
      case CANIF_CS_STARTED:
        buf = CANSM_CTRLMODETYPE_STARTED;
        break;
      default:
        buf = CANSM_CTRLMODETYPE_RESET;
        break;
    }

    TS_AtomicAssign8(
        CanSM_CtrlModeIndication[ControllerId],
        buf
        );
  }

  DBG_CANSM_CONTROLLERMODEINDICATION_EXIT(ControllerId,ControllerMode);
}

FUNC(void, CANSM_CODE) CanSM_TransceiverModeIndication (
  uint8 TransceiverId,
  CanTrcv_TrcvModeType TransceiverMode
)
{

  DBG_CANSM_TRANSCEIVERMODEINDICATION_ENTRY(TransceiverId,TransceiverMode);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
    CANSM_DET(CANSM_SID_TRANSCEIVERMODEINDICATION, CANSM_E_UNINIT);
  }
#if (CANSM_USE_TRANSCEIVER == STD_OFF)
  else
  {
    /* since CANSM_USE_TRANSCEIVER is not set, no transceiver is configured for any
     * network */
    CANSM_DET(CANSM_SID_TRANSCEIVERMODEINDICATION, CANSM_E_PARAM_TRANSCEIVER);
  }
#else /* CANSM_USE_TRANSCEIVER == STD_OFF */
  else if ( CANSM_NW_IDX_FROM_TRCV(TransceiverId) == CANSM_NETWORKS_NUM )
  {
    /* no network found */
    CANSM_DET(CANSM_SID_TRANSCEIVERMODEINDICATION, CANSM_E_PARAM_TRANSCEIVER);
  }
  else
#endif /* CANSM_USE_TRANSCEIVER == STD_OFF */
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
#if (CANSM_USE_TRANSCEIVER == STD_ON)
  {
    uint8 buf;
    switch (TransceiverMode)
    {
      case CANTRCV_TRCVMODE_NORMAL:
        buf = CANSM_TRCVMODETYPE_NORMAL;
        break;
      case CANTRCV_TRCVMODE_STANDBY:
        buf = CANSM_TRCVMODETYPE_STANDBY;
        break;
      default:
        buf = CANSM_TRCVMODETYPE_RESET;
        break;
    }

    TS_AtomicAssign8(
        CANSM_NW_INFO_TRCVMODEINDICATION(CANSM_NW_IDX_FROM_TRCV(TransceiverId)),
        buf
        );
#if (CANSM_NETWORKS_NUM == 1U)
    TS_PARAM_UNUSED(TransceiverId);
#endif /* CANSM_NETWORKS_NUM == 1U */
  }
#else /* CANSM_USE_TRANSCEIVER == STD_ON */
  TS_PARAM_UNUSED(TransceiverId);
  TS_PARAM_UNUSED(TransceiverMode);
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

  DBG_CANSM_TRANSCEIVERMODEINDICATION_EXIT(TransceiverId,TransceiverMode);
}

#if (CANSM_PNSUPPORT == STD_ON)
FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlagIndication (
  uint8 Transceiver
)
{

  DBG_CANSM_CLEARTRCVWUFFLAGINDICATION_ENTRY(Transceiver);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
    CANSM_DET(CANSM_SID_CLEARTRCVWUFFLAGINDICATION, CANSM_E_UNINIT);
  }
#if (CANSM_USE_TRANSCEIVER == STD_OFF)
  else
  {
    /* since CANSM_USE_TRANSCEIVER is not set, no transceiver is configured for any
     * network */
    CANSM_DET(CANSM_SID_CLEARTRCVWUFFLAGINDICATION, CANSM_E_PARAM_TRANSCEIVER);
  }
#else /* CANSM_USE_TRANSCEIVER == STD_OFF */
  else if ( CANSM_NW_IDX_FROM_TRCV(Transceiver) == CANSM_NETWORKS_NUM )
  {
    /* no network found */
    CANSM_DET(CANSM_SID_CLEARTRCVWUFFLAGINDICATION, CANSM_E_PARAM_TRANSCEIVER);
  }
  else
#endif /* CANSM_USE_TRANSCEIVER == STD_OFF */
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
  {
#if (CANSM_NETWORKS_NUM != 1U)
    uint8 nw = CANSM_NW_IDX_FROM_TRCV(Transceiver);
#endif /* CANSM_NETWORKS_NUM != 1U */

    TS_AtomicAssign8(CANSM_NW_INFO_TRCVCLEARWUFINDICATION(nw), TRUE);
  }
#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(Transceiver);
#endif /* CANSM_NETWORKS_NUM == 1U */

  DBG_CANSM_CLEARTRCVWUFFLAGINDICATION_EXIT(Transceiver);
}

FUNC(void, CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication (
  uint8 Transceiver
)
{

  DBG_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_ENTRY(Transceiver);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
    CANSM_DET(CANSM_SID_CHECKTRANSCEIVERWAKEFLAGINDICATION, CANSM_E_UNINIT);
  }
#if (CANSM_USE_TRANSCEIVER == STD_OFF)
  else
  {
    /* since CANSM_USE_TRANSCEIVER is not set, no transceiver is configured for any
     * network */
    CANSM_DET(CANSM_SID_CHECKTRANSCEIVERWAKEFLAGINDICATION, CANSM_E_PARAM_TRANSCEIVER);
  }
#else /* CANSM_USE_TRANSCEIVER == STD_OFF */
  else if ( CANSM_NW_IDX_FROM_TRCV(Transceiver) == CANSM_NETWORKS_NUM )
  {
    /* no network found */
    CANSM_DET(CANSM_SID_CHECKTRANSCEIVERWAKEFLAGINDICATION, CANSM_E_PARAM_TRANSCEIVER);
  }
  else
#endif /* CANSM_USE_TRANSCEIVER == STD_OFF */
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
  {
#if (CANSM_NETWORKS_NUM != 1U)
    uint8 nw = CANSM_NW_IDX_FROM_TRCV(Transceiver);
#endif /* CANSM_NETWORKS_NUM != 1U */

    TS_AtomicAssign8(CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION(nw), TRUE);
  }
#if (CANSM_NETWORKS_NUM == 1U)
  TS_PARAM_UNUSED(Transceiver);
#endif /* CANSM_NETWORKS_NUM == 1U */

  DBG_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_EXIT(Transceiver);
}

FUNC(void, CANSM_CODE) CanSM_ConfirmPnAvailability (
  uint8 TransceiverId
)
{

  DBG_CANSM_CONFIRMPNAVAILABILITY_ENTRY(TransceiverId);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
    CANSM_DET(CANSM_SID_CONFIRMPNAVAILABILITY, CANSM_E_UNINIT);
  }
#if (CANSM_USE_TRANSCEIVER == STD_OFF)
  else
  {
    /* since CANSM_USE_TRANSCEIVER is not set, no transceiver is configured for any
     * network */
    CANSM_DET(CANSM_SID_CONFIRMPNAVAILABILITY, CANSM_E_PARAM_TRANSCEIVER);
  }
#else /* CANSM_USE_TRANSCEIVER == STD_OFF */
  else if ( CANSM_NW_IDX_FROM_TRCV(TransceiverId) == CANSM_NETWORKS_NUM )
  {
    /* no network found */
    CANSM_DET(CANSM_SID_CONFIRMPNAVAILABILITY, CANSM_E_PARAM_TRANSCEIVER);
  }
  else
#endif /* CANSM_USE_TRANSCEIVER == STD_OFF */
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
  {
    /* confirm the PN availability to the CanNm module */
    CanNm_ConfirmPnAvailability(TransceiverId);
  }

  DBG_CANSM_CONFIRMPNAVAILABILITY_EXIT(TransceiverId);
}
#endif /* (CANSM_PNSUPPORT == STD_ON) */

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

