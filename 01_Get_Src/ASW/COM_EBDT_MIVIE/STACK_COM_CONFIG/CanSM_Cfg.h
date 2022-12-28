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
#if (!defined CANSM_CFG_H)
#define CANSM_CFG_H
/*==================[includes]==============================================*/

#include <ComStack_Types.h>         /* AUTOSAR communication stack types */

#include <CanSM_Int_Stc.h>          /* Module internal static header */
#include <CanSM_Api_Static.h>       /* CanSM_ConfigType */
#include <CanSM_Det_Cfg.h>          /* CANSM_DEV_ERROR_DETECT */

#include <CanIf.h>                  /* CAN Interface */
#include <Dem.h>                    /* AUTOSAR Dem */

/*==================[macros]================================================*/




/*------------------[Defensive programming]---------------------------------*/

#if (defined CANSM_DEFENSIVE_PROGRAMMING_ENABLED)
#error CANSM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define CANSM_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined CANSM_PRECONDITION_ASSERT_ENABLED)
#error CANSM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define CANSM_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined CANSM_POSTCONDITION_ASSERT_ENABLED)
#error CANSM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define CANSM_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined CANSM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error CANSM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define CANSM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined CANSM_INVARIANT_ASSERT_ENABLED)
#error CANSM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define CANSM_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined CANSM_STATIC_ASSERT_ENABLED)
#error CANSM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define CANSM_STATIC_ASSERT_ENABLED           STD_OFF





/** \brief Export symbolic name value */
#define CanSM_CMM_EB_atmo_Euro_6_2_redundant_sig 0U

#if (!defined CANSM_NO_SYMBOLS_WITHOUT_PREFIX)
/** \brief Export symbolic name value without prefix */
#define CMM_EB_atmo_Euro_6_2_redundant_sig 0U
#endif /* !defined CANSM_NO_SYMBOLS_WITHOUT_PREFIX */


/** \brief Export symbolic name value */
#define CanSM_Can_Cpp_Devaid 1U

#if (!defined CANSM_NO_SYMBOLS_WITHOUT_PREFIX)
/** \brief Export symbolic name value without prefix */
#define Can_Cpp_Devaid 1U
#endif /* !defined CANSM_NO_SYMBOLS_WITHOUT_PREFIX */


/** \brief Switch for DEM to DET reporting */
#define CANSM_PROD_ERR_HANDLING_BUS_OFF   TS_PROD_ERR_DISABLE


/** \brief Switch for version info API */
#define CANSM_VERSION_INFO_API STD_OFF

/** \brief Partial Networking Support */
#define CANSM_PNSUPPORT STD_OFF

/** \brief Maximum amount of mode change request repetitions */
#define CANSM_MODEREQ_MAX 3U

/** \brief Time duration after which a mode change request is repeated */
#define CANSM_MODEREQ_REPEAT_TIME 100U

/** \brief use transceiver driver calls or not */
#define CANSM_USE_TRANSCEIVER STD_OFF

/** \brief Transceiver resources present in code */
#define CANSM_TRCV_RESOURCES STD_OFF


/** \brief Duration until bus-off free communication is assumed */
#define CANSM_BOR_TIME_TX_ENSURED(nw) 200U


/** \brief Duration to stay in level 1 check before restart of communication */
#define CANSM_BOR_TIME_L1(nw) 5U


/** \brief Duration to stay in level 2 check before restart of communication */
#define CANSM_BOR_TIME_L2(nw) 25U


/** \brief bus-off recovery L1 to L2 Threshold */
#define CANSM_BOR_COUNTER_L1_TO_L2(nw) 10U

/** \brief BOR Tx Confirmation Polling */
#define CANSM_BOR_TX_CONFIRMATION_POLLING(nw) FALSE

/** \brief Partial networking */
#define CANSM_PARTIALNETWORKING(nw) (CanSM_NetworkConfig[(nw)].PartialNetworking)


/** \brief Use CanIf_GetTxConfirmationState API */
#define CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE STD_OFF

/** \brief Use CanSMBorTimeTxEnsured for bus-off check */
#define CANSM_USE_BOR_TIME_TX_ENSURED STD_ON

/** \brief number of networks used */
#define CANSM_NETWORKS_NUM 2U

/** \brief number of controllers used */
#define CANSM_CONTROLLERS_NUM 2U

/** \brief highest controller id used + 1 */
#define CANSM_CONTROLLERS_ID_NUM 2U

/** \brief special value to indicate that CanSM_ControllerModeIndication was not invoked
 *  with a meaningful value since last reset
 */
#define CANSM_CTRLMODETYPE_RESET 0U

/** \brief CanSM_ControllerModeIndication was last invoked with CANIF_CS_SLEEP */
#define CANSM_CTRLMODETYPE_SLEEP 1U

/** \brief CanSM_ControllerModeIndication was last invoked with CANIF_CS_STARTED */
#define CANSM_CTRLMODETYPE_STARTED 2U

/** \brief CanSM_ControllerModeIndication was last invoked with CANIF_CS_STOPPED */
#define CANSM_CTRLMODETYPE_STOPPED 3U

/** \brief number of transceivers used */
#define CANSM_TRANSCEIVERS_NUM 0U



 

/** \brief DEM Event to report bus off error for given network */
#define CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF(nw) (CanSM_NetworkConfig[(nw)].EventIdBusOff)



/** \brief Index of controller of this network */
#define CANSM_NW_CONFIG_CTRL_START(nw) (nw)

/** \brief Number of controllers in this network */
#define CANSM_NW_CONFIG_CTRL_NUM(nw) 1U


/** \brief access to bor state machine timer of network \a nw */
#define CANSM_NW_INFO_TIMER(nw) (CanSM_NetworkInfo[(nw)].BoTimer)

/** \brief access to bus-off counter of network \a nw */
#define CANSM_NW_INFO_BOR_COUNTER(nw) (CanSM_NetworkInfo[(nw)].BoCounter)

/** \brief access to current state of network \a nw */
#define CANSM_NW_INFO_STATE(nw) (CanSM_NetworkInfo[(nw)].NwState)

/** \brief access to bus-off event flag of network \a nw */
#define CANSM_NW_INFO_BUSOFF(nw) (CanSM_NetworkInfo[(nw)].BusOffEvent)

/** \brief access to current internal state of network \a nw */
#define CANSM_NW_INFO_INTERNALSTATE(nw) (CanSM_NetworkInfo[(nw)].InternalState)

/** \brief access to mode change request repetitions timer of network \a nw */
#define CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER(nw) (CanSM_NetworkInfo[(nw)].ModeReqRepetitionTimer)

#if (CANSM_PNSUPPORT == STD_ON)
/** \brief access to requested State member of network \a nw */
#define CANSM_NW_INFO_REQ_STATE(nw) (CanSM_NetworkInfo[(nw)].reqState)
#endif /* CANSM_PNSUPPORT == STD_ON */





/** \brief access to mode change request repetitions counter of network \a nw */
#define CANSM_NW_INFO_MODE_REQUEST_REPETITION_COUNTER(nw) (CanSM_NetworkInfo[(nw)].ModeReqRepetitionCounter)



/** \brief check if network handle is valid */
#define CANSM_NW_HANDLE_IS_VALID(nw) ((nw) < 2U)

/** \brief convert network handle to array index */
#define CANSM_NW_IDX_FROM_HANDLE(nw) (nw)

/** \brief convert network array index to handle */
#define CANSM_NW_HANDLE_FROM_IDX(nw) ((NetworkHandleType)(nw))


 


  
/** \brief Get controller \a ctrl from controller list */
#define CANSM_NW_CONFIG_CTRL(ctrl) (CanSM_NetworkConfig[(ctrl)].ControllerId)
  


/** \brief Convert Controller id to array index for internal network data
 *
 * \param[in] ctrl Controller Id
 *
 * \return The array index of the network, CANSM_NETWORKS_NUM on lookup failure
 */
#define CANSM_NW_IDX_FROM_CONTROLLER(ctrl) \
  ( (ctrl) < CANSM_CONTROLLERS_ID_NUM ? CanSM_ControllerNetworkLut[(ctrl)] : CANSM_NETWORKS_NUM )



/*==================[type definitions]======================================*/


/** \brief configuration data for one network */
typedef struct {



  Dem_EventIdType EventIdBusOff; /**< Event Id to be passed to Dem */

  uint8 ControllerId; /**< Id of CAN controller */





} CanSM_NetworkConfigType;


/** \brief States and sub-states of internal state machine, most taken from ASR40 SWS */
typedef enum {
  CANSM_S_NOIN,                         /**< State according to ASR40 SWS Figure 7-1 */

  CANSM_S_RNOCO_CAN_CC_STOPPED,         /**< State according to ASR40 SWS rev 3 Figure 7-4 */
  CANSM_S_RNOCO_CAN_CC_SLEEP,           /**< State according to ASR40 SWS rev 3 Figure 7-4 */
#if (CANSM_USE_TRANSCEIVER == STD_ON)
  CANSM_S_RNOCO_CAN_TRCV_NORMAL,        /**< State according to ASR40 SWS rev 3 Figure 7-4 */
  CANSM_S_RNOCO_CAN_TRCV_STANDBY,       /**< State according to ASR40 SWS rev 3 Figure 7-4 */
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

#if (CANSM_PNSUPPORT == STD_ON)
  CANSM_S_PN_CLEAR_WUF,                 /**< State according to ASR40 rev 3 SWS Figure 7-3 */
  CANSM_S_PN_CC_STOPPED,                /**< State according to ASR40 rev 3 SWS Figure 7-3 */
  CANSM_S_PN_TRCV_NORMAL,               /**< State according to ASR40 rev 3 SWS Figure 7-3 */
  CANSM_S_PN_TRCV_STANDBY,              /**< State according to ASR40 rev 3 SWS Figure 7-3 */
  CANSM_S_PN_CC_SLEEP,                  /**< State according to ASR40 rev 3 SWS Figure 7-3 */
  CANSM_S_PN_CHECK_WFLAG_IN_CC_SLEEP,   /**< State according to ASR40 rev 3 SWS Figure 7-3 */
  CANSM_S_PN_CHECK_WFLAG_IN_NOT_CC_SLEEP,/**< State according to ASR40 rev 3 SWS Figure 7-3 */
#endif /* (CANSM_PNSUPPORT == STD_ON) */


  CANSM_S_NOCO,                         /**< State according to ASR40 SWS Figure 7-1 */

#if (CANSM_USE_TRANSCEIVER == STD_ON)
  CANSM_S_RFUCO_CAN_TRCV_NORMAL,        /**< State according to ASR40 SWS Figure 7-3 */
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */
  CANSM_S_RFUCO_CAN_CC_STOPPED,         /**< State according to ASR40 SWS Figure 7-3 */
  CANSM_S_RFUCO_CAN_CC_STARTED,         /**< State according to ASR40 SWS Figure 7-3 */

  CANSM_S_FUCO_BUS_OFF_CHECK,           /**< State according to ASR40 SWS Figure 7-4 */
  CANSM_S_FUCO_NO_BUS_OFF,              /**< State according to ASR40 SWS Figure 7-4 */

  CANSM_S_FUCO_RESTART_CC,              /**< State according to ASR40 SWS Figure 7-4 */
  CANSM_S_FUCO_TX_OFF,                  /**< State according to ASR40 SWS Figure 7-4 */

  CANSM_S_SICO                          /**< State according to ASR40 SWS Figure 7-1 */
} CanSM_InternalStateType;

/** \brief Transitions between states of type CanSM_InternalStateType.
 *
 * The transitions are executed by calling CanSM_DoTransitionSequence.
 */
typedef enum
{
  CANSM_T_NONE,                         /**< Special value: no transition shall be fired */

  CANSM_T_RNOCO_INITIAL,                /**< Initial transition to RNOCO (E_PRE_NO_COM) */
  CANSM_T_RNOCO_DEINIT_INITIAL,         /**< Choice between Partial Network on/off */

  CANSM_T_RNOCO_CC_INITIAL,             /**< Transition to CANSM_S_RNOCO_CAN_CC_STOPPED */
  CANSM_T_RNOCO_CC_STOPPED,             /**< Transition according to ASR40 SWS rev 3 Figure 7-4 */
  CANSM_T_RNOCO_CC_SLEEP,               /**< Transition according to ASR40 SWS rev 3 Figure 7-4 */

#if (CANSM_USE_TRANSCEIVER == STD_ON)
  CANSM_T_RNOCO_TRCV_NORMAL,            /**< Transition according to ASR40 SWS rev 3 Figure 7-4 */
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */

#if (CANSM_PNSUPPORT == STD_ON)
  CANSM_T_PN_DEINIT,                    /**< Transition to CANSM_S_PN_CLEAR_WUF */
  CANSM_T_PN_CLEAR_WUF_INDICATED,       /**< Transition to CANSM_S_PN_CC_STOPPED */
  CANSM_T_PN_CC_STOPPED_INDICATED,      /**< Transition to CANSM_S_PN_TRCV_NORMAL */
  CANSM_T_PN_TRCV_NORMAL_INDICATED,     /**< Transition to CANSM_S_PN_TRCV_STANDBY */
  CANSM_T_PN_TRCV_STANDBY_INDICATED,    /**< Transition to CANSM_S_PN_CC_SLEEP */
  CANSM_T_PN_CC_SLEEP_INDICATED,        /**< Transition to CANSM_S_PN_CHECK_WFLAG_IN_CC_SLEEP */
  CANSM_T_PN_CC_SLEEP_TIMEOUT,          /**< Transition to CANSM_S_PN_CHECK_WFLAG_IN_NOT_CC_SLEEP */
#endif /* (CANSM_PNSUPPORT == STD_ON) */

  CANSM_T_RNOCO_FINAL,                  /**< Transition to CANSM_S_NOCO */

  CANSM_T_RFUCO_INITIAL,                /**< Branches to CANSM_T_RFUCO_TRCV_INITIAL (if transceiver
                                         *   is present) or CANSM_T_RFUCO_TRCV_NORMAL */
#if (CANSM_USE_TRANSCEIVER == STD_ON)
  CANSM_T_RFUCO_TRCV_INITIAL,           /**< Transition to CANSM_S_RFUCO_CAN_TRCV_NORMAL */
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */
  CANSM_T_RFUCO_TRCV_NORMAL,            /**< Transition according to ASR40 SWS Figure 7-3 */
  CANSM_T_RFUCO_CC_STOPPED,             /**< Transition according to ASR40 SWS Figure 7-3 */
  CANSM_T_RFUCO_CC_STARTED,             /**< Transition according to ASR40 SWS Figure 7-3 */

  CANSM_T_FUCO_SICO,                    /**< Transition from CANSM_S_FUCO_BUS_OFF_CHECK and
                                         *   CANSM_S_FUCO_NO_BUS_OFF to CANSM_S_SICO */
  CANSM_T_FUCO_NOCO,                    /**< Transition from CANSM_S_FUCO to CANSM_S_NOCO */
  CANSM_T_SICO_FUCO,                    /**< Transition according to ASR40 SWS Figure 7-1 */

  CANSM_T_FUCO_HANDLE_BUS_OFF,          /**< All transitions to CANSM_S_FUCO_RESTART_CC */
  CANSM_T_FUCO_TX_OFF,                  /**< Transition according to ASR40 SWS Figure 7-4 */
  CANSM_T_FUCO_TX_ON,                   /**< Transition according to ASR40 SWS Figure 7-4 */
  CANSM_TRY_T_FUCO_BUS_OFF_PASSIVE      /**< Try transition according to ASR40 SWS Figure 7-4,
                                         *   unless there is a concurrent transition to
                                         *   silent communication */
} CanSM_TransitionType;

/** \brief runtime information for one network */
typedef struct {
  uint16 BoTimer; /**< timer for bus-off recovery state machine */
  uint16 ModeReqRepetitionTimer; /**< timer for mode change request repetitions */
#if (CANSM_PNSUPPORT == STD_ON)
  uint8 reqState; /** < store requested state for CanSM_TxTimeoutException */
#endif /* CANSM_PNSUPPORT == STD_ON */
  uint8 InternalState; /**< current internal state */
  uint8 NwState; /**< current network state */
  uint8 BusOffEvent; /**< indicates that a bus-off event has occured */
  uint8 BoCounter; /**< bus-off counter */
  uint8 ModeReqRepetitionCounter; /**< mode change request repetition counter */
#if (CANSM_TRCV_RESOURCES == STD_ON)
  uint8 TrcvModeIndication; /**< indication by last CanSM_TransceiverModeIndication
                                 (CanSM specific representation), or CANSM_TRCVMODETYPE_RESET */
#endif /* CANSM_TRCV_RESOURCES == STD_ON */
#if (CANSM_PNSUPPORT == STD_ON)
  boolean TrcvClearWUFIndication; /**< indication by last CanSM_ClearTrcvWufFlagIndication */
  boolean TrcvCheckWakeFlagIndication; /**< indication by last CanSM_CheckTransceiverWakeFlagIndication */
#endif /* CANSM_PNSUPPORT == STD_ON */
} CanSM_NetworkInfoType;

/*==================[external constants]====================================*/

#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/** \brief configuration of all networks */
extern CONST(CanSM_NetworkConfigType, CANSM_APPL_CONST) CanSM_NetworkConfig[CANSM_NETWORKS_NUM];

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>


#define CANSM_START_SEC_CONFIG_DATA_8
#include <MemMap.h>

/** \brief Empty configuration structure to be passed to CanSM_Init() */
extern CONST(CanSM_ConfigType, CANSM_APPL_CONST) CanSMConfiguration;



/**
 * \brief controller to network handle lookup table
 *
 * \note may contain holes, these have the value CANSM_NETWORKS_NUM
 */
extern CONST(uint8, CANSM_APPL_CONST) CanSM_ControllerNetworkLut[CANSM_CONTROLLERS_ID_NUM];



#define CANSM_STOP_SEC_CONFIG_DATA_8
#include <MemMap.h>

/*==================[external data]=========================================*/

#define CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>


/** \brief run-time information for all networks */
extern VAR(CanSM_NetworkInfoType, CANSM_VAR) CanSM_NetworkInfo[CANSM_NETWORKS_NUM];


/** \brief Contains indication by last CanSM_ControllerModeIndication (CanSM specific
 *  representation), or CANSM_CTRLMODETYPE_RESET
 */
extern VAR(uint8, CANSM_VAR) CanSM_CtrlModeIndication[CANSM_CONTROLLERS_ID_NUM];

#define CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[external function declarations]========================*/



#endif /* if !defined( CANSM_CFG_H ) */
/*==================[end of file]===========================================*/

