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
#if (!defined CANSM_TRACE_H)
#define CANSM_TRACE_H
/*==================[inclusions]============================================*/


/*==================[macros]================================================*/

#ifndef DBG_CANSM_GETNETWORKHANDLEFROMINDEX_ENTRY
/** \brief Entry point of function CanSM_GetNetworkHandleFromIndex() */
#define DBG_CANSM_GETNETWORKHANDLEFROMINDEX_ENTRY(a)
#endif

#ifndef DBG_CANSM_GETNETWORKHANDLEFROMINDEX_EXIT
/** \brief Exit point of function CanSM_GetNetworkHandleFromIndex() */
#define DBG_CANSM_GETNETWORKHANDLEFROMINDEX_EXIT(a,b)
#endif

#ifndef DBG_CANSM_NETWORKHANDLEISVALID_ENTRY
/** \brief Entry point of function CanSM_NetworkHandleIsValid() */
#define DBG_CANSM_NETWORKHANDLEISVALID_ENTRY(a)
#endif

#ifndef DBG_CANSM_NETWORKHANDLEISVALID_EXIT
/** \brief Exit point of function CanSM_NetworkHandleIsValid() */
#define DBG_CANSM_NETWORKHANDLEISVALID_EXIT(a,b)
#endif

#ifndef DBG_CANSM_CONTROLLERBUSOFF_ENTRY
/** \brief Entry point of function CanSM_ControllerBusOff() */
#define DBG_CANSM_CONTROLLERBUSOFF_ENTRY(a)
#endif

#ifndef DBG_CANSM_CONTROLLERBUSOFF_EXIT
/** \brief Exit point of function CanSM_ControllerBusOff() */
#define DBG_CANSM_CONTROLLERBUSOFF_EXIT(a)
#endif

#ifndef DBG_CANSM_CONTROLLERMODEINDICATION_ENTRY
/** \brief Entry point of function CanSM_ControllerModeIndication() */
#define DBG_CANSM_CONTROLLERMODEINDICATION_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_CONTROLLERMODEINDICATION_EXIT
/** \brief Exit point of function CanSM_ControllerModeIndication() */
#define DBG_CANSM_CONTROLLERMODEINDICATION_EXIT(a,b)
#endif

#ifndef DBG_CANSM_TRANSCEIVERMODEINDICATION_ENTRY
/** \brief Entry point of function CanSM_TransceiverModeIndication() */
#define DBG_CANSM_TRANSCEIVERMODEINDICATION_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_TRANSCEIVERMODEINDICATION_EXIT
/** \brief Exit point of function CanSM_TransceiverModeIndication() */
#define DBG_CANSM_TRANSCEIVERMODEINDICATION_EXIT(a,b)
#endif

#ifndef DBG_CANSM_CLEARTRCVWUFFLAGINDICATION_ENTRY
/** \brief Entry point of function CanSM_ClearTrcvWufFlagIndication() */
#define DBG_CANSM_CLEARTRCVWUFFLAGINDICATION_ENTRY(a)
#endif

#ifndef DBG_CANSM_CLEARTRCVWUFFLAGINDICATION_EXIT
/** \brief Exit point of function CanSM_ClearTrcvWufFlagIndication() */
#define DBG_CANSM_CLEARTRCVWUFFLAGINDICATION_EXIT(a)
#endif

#ifndef DBG_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_ENTRY
/** \brief Entry point of function CanSM_CheckTransceiverWakeFlagIndication() */
#define DBG_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_ENTRY(a)
#endif

#ifndef DBG_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_EXIT
/** \brief Exit point of function CanSM_CheckTransceiverWakeFlagIndication() */
#define DBG_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_EXIT(a)
#endif

#ifndef DBG_CANSM_CONFIRMPNAVAILABILITY_ENTRY
/** \brief Entry point of function CanSM_ConfirmPnAvailability() */
#define DBG_CANSM_CONFIRMPNAVAILABILITY_ENTRY(a)
#endif

#ifndef DBG_CANSM_CONFIRMPNAVAILABILITY_EXIT
/** \brief Exit point of function CanSM_ConfirmPnAvailability() */
#define DBG_CANSM_CONFIRMPNAVAILABILITY_EXIT(a)
#endif

#ifndef DBG_CANSM_GETCURRENTCOMMODE_ENTRY
/** \brief Entry point of function CanSM_GetCurrentComMode() */
#define DBG_CANSM_GETCURRENTCOMMODE_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_GETCURRENTCOMMODE_EXIT
/** \brief Exit point of function CanSM_GetCurrentComMode() */
#define DBG_CANSM_GETCURRENTCOMMODE_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_GETVERSIONINFO_ENTRY
/** \brief Entry point of function CanSM_GetVersionInfo() */
#define DBG_CANSM_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_CANSM_GETVERSIONINFO_EXIT
/** \brief Exit point of function CanSM_GetVersionInfo() */
#define DBG_CANSM_GETVERSIONINFO_EXIT(a)
#endif

#ifndef DBG_CANSM_INIT_ENTRY
/** \brief Entry point of function CanSM_Init() */
#define DBG_CANSM_INIT_ENTRY(a)
#endif

#ifndef DBG_CANSM_GLOBALINIT
/** \brief Change of CanSM_GlobalInit */
#define DBG_CANSM_GLOBALINIT(a,b)
#endif

#ifndef DBG_CANSM_INIT_EXIT
/** \brief Exit point of function CanSM_Init() */
#define DBG_CANSM_INIT_EXIT(a)
#endif

#ifndef DBG_CANSM_MAINFUNCTION_ENTRY
/** \brief Entry point of function CanSM_MainFunction() */
#define DBG_CANSM_MAINFUNCTION_ENTRY()
#endif

#ifndef DBG_CANSM_MAINFUNCTION_EXIT
/** \brief Exit point of function CanSM_MainFunction() */
#define DBG_CANSM_MAINFUNCTION_EXIT()
#endif

#ifndef DBG_CANSM_REQUESTCOMMODE_ENTRY
/** \brief Entry point of function CanSM_RequestComMode() */
#define DBG_CANSM_REQUESTCOMMODE_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_REQUESTCOMMODE_EXIT
/** \brief Exit point of function CanSM_RequestComMode() */
#define DBG_CANSM_REQUESTCOMMODE_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_TXTIMEOUTEXCEPTION_ENTRY
/** \brief Entry point of function CanSM_TxTimeoutException() */
#define DBG_CANSM_TXTIMEOUTEXCEPTION_ENTRY(a)
#endif

#ifndef DBG_CANSM_TXTIMEOUTEXCEPTION_EXIT
/** \brief Exit point of function CanSM_TxTimeoutException() */
#define DBG_CANSM_TXTIMEOUTEXCEPTION_EXIT(a)
#endif

#ifndef DBG_CANSM_REQUESTCOMMODEINTERNAL_ENTRY
/** \brief Entry point of function CanSM_RequestComModeInternal() */
#define DBG_CANSM_REQUESTCOMMODEINTERNAL_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_REQUESTCOMMODEINTERNAL_EXIT
/** \brief Exit point of function CanSM_RequestComModeInternal() */
#define DBG_CANSM_REQUESTCOMMODEINTERNAL_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_STATENOCOMMUNICATION_ENTRY
/** \brief Entry point of function CanSM_StateNoCommunication() */
#define DBG_CANSM_STATENOCOMMUNICATION_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_STATENOCOMMUNICATION_EXIT
/** \brief Exit point of function CanSM_StateNoCommunication() */
#define DBG_CANSM_STATENOCOMMUNICATION_EXIT(a,b)
#endif

#ifndef DBG_CANSM_STATESILENTCOMMUNICATION_ENTRY
/** \brief Entry point of function CanSM_StateSilentCommunication() */
#define DBG_CANSM_STATESILENTCOMMUNICATION_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_STATESILENTCOMMUNICATION_EXIT
/** \brief Exit point of function CanSM_StateSilentCommunication() */
#define DBG_CANSM_STATESILENTCOMMUNICATION_EXIT(a,b)
#endif

#ifndef DBG_CANSM_STATEFULLCOMMUNICATION_ENTRY
/** \brief Entry point of function CanSM_StateFullCommunication() */
#define DBG_CANSM_STATEFULLCOMMUNICATION_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_STATEFULLCOMMUNICATION_EXIT
/** \brief Exit point of function CanSM_StateFullCommunication() */
#define DBG_CANSM_STATEFULLCOMMUNICATION_EXIT(a,b)
#endif

#ifndef DBG_CANSM_ISWAITINGFORMODEINDICATION_ENTRY
/** \brief Entry point of function CanSM_IsWaitingForModeIndication() */
#define DBG_CANSM_ISWAITINGFORMODEINDICATION_ENTRY(a)
#endif

#ifndef DBG_CANSM_ISWAITINGFORMODEINDICATION_EXIT
/** \brief Exit point of function CanSM_IsWaitingForModeIndication() */
#define DBG_CANSM_ISWAITINGFORMODEINDICATION_EXIT(a,b)
#endif

#ifndef DBG_CANSM_MAINFUNCTIONINTERNAL_ENTRY
/** \brief Entry point of function CanSM_MainFunctionInternal() */
#define DBG_CANSM_MAINFUNCTIONINTERNAL_ENTRY(a)
#endif

#ifndef DBG_CANSM_MAINFUNCTIONINTERNAL_EXIT
/** \brief Exit point of function CanSM_MainFunctionInternal() */
#define DBG_CANSM_MAINFUNCTIONINTERNAL_EXIT(a)
#endif

#ifndef DBG_CANSM_DOTRANSITIONSEQUENCE_ENTRY
/** \brief Entry point of function CanSM_DoTransitionSequence() */
#define DBG_CANSM_DOTRANSITIONSEQUENCE_ENTRY(a,b,c)
#endif

#ifndef DBG_CANSM_DOTRANSITIONSEQUENCE_EXIT
/** \brief Exit point of function CanSM_DoTransitionSequence() */
#define DBG_CANSM_DOTRANSITIONSEQUENCE_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_DOTRANSITIONSWITCH_ENTRY
/** \brief Entry point of function CanSM_DoTransitionSwitch() */
#define DBG_CANSM_DOTRANSITIONSWITCH_ENTRY(a,b,c,d)
#endif

#ifndef DBG_CANSM_DOTRANSITIONSWITCH_EXIT
/** \brief Exit point of function CanSM_DoTransitionSwitch() */
#define DBG_CANSM_DOTRANSITIONSWITCH_EXIT(a,b,c,d)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_INITIAL_ENTRY
/** \brief Entry point of function CanSM_Do_T_RNOCO_INITIAL() */
#define DBG_CANSM_DO_T_RNOCO_INITIAL_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_INITIAL_EXIT
/** \brief Exit point of function CanSM_Do_T_RNOCO_INITIAL() */
#define DBG_CANSM_DO_T_RNOCO_INITIAL_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_DEINIT_INITIAL_ENTRY
/** \brief Entry point of function CanSM_Do_T_RNOCO_DEINIT_INITIAL() */
#define DBG_CANSM_DO_T_RNOCO_DEINIT_INITIAL_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_DEINIT_INITIAL_EXIT
/** \brief Exit point of function CanSM_Do_T_RNOCO_DEINIT_INITIAL() */
#define DBG_CANSM_DO_T_RNOCO_DEINIT_INITIAL_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_CC_INITIAL_ENTRY
/** \brief Entry point of function CanSM_Do_T_RNOCO_CC_INITIAL() */
#define DBG_CANSM_DO_T_RNOCO_CC_INITIAL_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_CC_INITIAL_EXIT
/** \brief Exit point of function CanSM_Do_T_RNOCO_CC_INITIAL() */
#define DBG_CANSM_DO_T_RNOCO_CC_INITIAL_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_CC_STOPPED_ENTRY
/** \brief Entry point of function CanSM_Do_T_RNOCO_CC_STOPPED() */
#define DBG_CANSM_DO_T_RNOCO_CC_STOPPED_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_CC_STOPPED_EXIT
/** \brief Exit point of function CanSM_Do_T_RNOCO_CC_STOPPED() */
#define DBG_CANSM_DO_T_RNOCO_CC_STOPPED_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_CC_SLEEP_ENTRY
/** \brief Entry point of function CanSM_Do_T_RNOCO_CC_SLEEP() */
#define DBG_CANSM_DO_T_RNOCO_CC_SLEEP_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_CC_SLEEP_EXIT
/** \brief Exit point of function CanSM_Do_T_RNOCO_CC_SLEEP() */
#define DBG_CANSM_DO_T_RNOCO_CC_SLEEP_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_TRCV_NORMAL_ENTRY
/** \brief Entry point of function CanSM_Do_T_RNOCO_TRCV_NORMAL() */
#define DBG_CANSM_DO_T_RNOCO_TRCV_NORMAL_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_TRCV_NORMAL_EXIT
/** \brief Exit point of function CanSM_Do_T_RNOCO_TRCV_NORMAL() */
#define DBG_CANSM_DO_T_RNOCO_TRCV_NORMAL_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_FINAL_ENTRY
/** \brief Entry point of function CanSM_Do_T_RNOCO_FINAL() */
#define DBG_CANSM_DO_T_RNOCO_FINAL_ENTRY(a)
#endif

#ifndef DBG_CANSM_DO_T_RNOCO_FINAL_EXIT
/** \brief Exit point of function CanSM_Do_T_RNOCO_FINAL() */
#define DBG_CANSM_DO_T_RNOCO_FINAL_EXIT(a)
#endif

#ifndef DBG_CANSM_DO_T_PN_DEINIT_ENTRY
/** \brief Entry point of function CanSM_Do_T_PN_DEINIT() */
#define DBG_CANSM_DO_T_PN_DEINIT_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_DEINIT_EXIT
/** \brief Exit point of function CanSM_Do_T_PN_DEINIT() */
#define DBG_CANSM_DO_T_PN_DEINIT_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_CLEAR_WUF_INDICATED_ENTRY
/** \brief Entry point of function CanSM_Do_T_PN_CLEAR_WUF_INDICATED() */
#define DBG_CANSM_DO_T_PN_CLEAR_WUF_INDICATED_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_CLEAR_WUF_INDICATED_EXIT
/** \brief Exit point of function CanSM_Do_T_PN_CLEAR_WUF_INDICATED() */
#define DBG_CANSM_DO_T_PN_CLEAR_WUF_INDICATED_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_CC_STOPPED_INDICATED_ENTRY
/** \brief Entry point of function CanSM_Do_T_PN_CC_STOPPED_INDICATED() */
#define DBG_CANSM_DO_T_PN_CC_STOPPED_INDICATED_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_CC_STOPPED_INDICATED_EXIT
/** \brief Exit point of function CanSM_Do_T_PN_CC_STOPPED_INDICATED() */
#define DBG_CANSM_DO_T_PN_CC_STOPPED_INDICATED_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_TRCV_NORMAL_INDICATED_ENTRY
/** \brief Entry point of function CanSM_Do_T_PN_TRCV_NORMAL_INDICATED() */
#define DBG_CANSM_DO_T_PN_TRCV_NORMAL_INDICATED_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_TRCV_NORMAL_INDICATED_EXIT
/** \brief Exit point of function CanSM_Do_T_PN_TRCV_NORMAL_INDICATED() */
#define DBG_CANSM_DO_T_PN_TRCV_NORMAL_INDICATED_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_TRCV_STANDBY_INDICATED_ENTRY
/** \brief Entry point of function CanSM_Do_T_PN_TRCV_STANDBY_INDICATED() */
#define DBG_CANSM_DO_T_PN_TRCV_STANDBY_INDICATED_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_TRCV_STANDBY_INDICATED_EXIT
/** \brief Exit point of function CanSM_Do_T_PN_TRCV_STANDBY_INDICATED() */
#define DBG_CANSM_DO_T_PN_TRCV_STANDBY_INDICATED_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_CC_SLEEP_INDICATED_ENTRY
/** \brief Entry point of function CanSM_Do_T_PN_CC_SLEEP_INDICATED() */
#define DBG_CANSM_DO_T_PN_CC_SLEEP_INDICATED_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_CC_SLEEP_INDICATED_EXIT
/** \brief Exit point of function CanSM_Do_T_PN_CC_SLEEP_INDICATED() */
#define DBG_CANSM_DO_T_PN_CC_SLEEP_INDICATED_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_CC_SLEEP_TIMEOUT_ENTRY
/** \brief Entry point of function CanSM_Do_T_PN_CC_SLEEP_TIMEOUT() */
#define DBG_CANSM_DO_T_PN_CC_SLEEP_TIMEOUT_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_PN_CC_SLEEP_TIMEOUT_EXIT
/** \brief Exit point of function CanSM_Do_T_PN_CC_SLEEP_TIMEOUT() */
#define DBG_CANSM_DO_T_PN_CC_SLEEP_TIMEOUT_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_INITIAL_ENTRY
/** \brief Entry point of function CanSM_Do_T_RFUCO_INITIAL() */
#define DBG_CANSM_DO_T_RFUCO_INITIAL_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_INITIAL_EXIT
/** \brief Exit point of function CanSM_Do_T_RFUCO_INITIAL() */
#define DBG_CANSM_DO_T_RFUCO_INITIAL_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_TRCV_INITIAL_ENTRY
/** \brief Entry point of function CanSM_Do_T_RFUCO_TRCV_INITIAL() */
#define DBG_CANSM_DO_T_RFUCO_TRCV_INITIAL_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_TRCV_INITIAL_EXIT
/** \brief Exit point of function CanSM_Do_T_RFUCO_TRCV_INITIAL() */
#define DBG_CANSM_DO_T_RFUCO_TRCV_INITIAL_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_TRCV_NORMAL_ENTRY
/** \brief Entry point of function CanSM_Do_T_RFUCO_TRCV_NORMAL() */
#define DBG_CANSM_DO_T_RFUCO_TRCV_NORMAL_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_TRCV_NORMAL_EXIT
/** \brief Exit point of function CanSM_Do_T_RFUCO_TRCV_NORMAL() */
#define DBG_CANSM_DO_T_RFUCO_TRCV_NORMAL_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_CC_STOPPED_ENTRY
/** \brief Entry point of function CanSM_Do_T_RFUCO_CC_STOPPED() */
#define DBG_CANSM_DO_T_RFUCO_CC_STOPPED_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_CC_STOPPED_EXIT
/** \brief Exit point of function CanSM_Do_T_RFUCO_CC_STOPPED() */
#define DBG_CANSM_DO_T_RFUCO_CC_STOPPED_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_CC_STARTED_ENTRY
/** \brief Entry point of function CanSM_Do_T_RFUCO_CC_STARTED() */
#define DBG_CANSM_DO_T_RFUCO_CC_STARTED_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_RFUCO_CC_STARTED_EXIT
/** \brief Exit point of function CanSM_Do_T_RFUCO_CC_STARTED() */
#define DBG_CANSM_DO_T_RFUCO_CC_STARTED_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_FUCO_SICO_ENTRY
/** \brief Entry point of function CanSM_Do_T_FUCO_SICO() */
#define DBG_CANSM_DO_T_FUCO_SICO_ENTRY(a)
#endif

#ifndef DBG_CANSM_DO_T_FUCO_SICO_EXIT
/** \brief Exit point of function CanSM_Do_T_FUCO_SICO() */
#define DBG_CANSM_DO_T_FUCO_SICO_EXIT(a)
#endif

#ifndef DBG_CANSM_DO_T_SICO_FUCO_ENTRY
/** \brief Entry point of function CanSM_Do_T_SICO_FUCO() */
#define DBG_CANSM_DO_T_SICO_FUCO_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_SICO_FUCO_EXIT
/** \brief Exit point of function CanSM_Do_T_SICO_FUCO() */
#define DBG_CANSM_DO_T_SICO_FUCO_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_FUCO_HANDLE_BUS_OFF_ENTRY
/** \brief Entry point of function CanSM_Do_T_FUCO_HANDLE_BUS_OFF() */
#define DBG_CANSM_DO_T_FUCO_HANDLE_BUS_OFF_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DO_T_FUCO_HANDLE_BUS_OFF_EXIT
/** \brief Exit point of function CanSM_Do_T_FUCO_HANDLE_BUS_OFF() */
#define DBG_CANSM_DO_T_FUCO_HANDLE_BUS_OFF_EXIT(a,b)
#endif

#ifndef DBG_CANSM_DO_T_FUCO_TX_OFF_ENTRY
/** \brief Entry point of function CanSM_Do_T_FUCO_TX_OFF() */
#define DBG_CANSM_DO_T_FUCO_TX_OFF_ENTRY(a)
#endif

#ifndef DBG_CANSM_DO_T_FUCO_TX_OFF_EXIT
/** \brief Exit point of function CanSM_Do_T_FUCO_TX_OFF() */
#define DBG_CANSM_DO_T_FUCO_TX_OFF_EXIT(a)
#endif

#ifndef DBG_CANSM_DO_T_FUCO_TX_ON_ENTRY
/** \brief Entry point of function CanSM_Do_T_FUCO_TX_ON() */
#define DBG_CANSM_DO_T_FUCO_TX_ON_ENTRY(a)
#endif

#ifndef DBG_CANSM_DO_T_FUCO_TX_ON_EXIT
/** \brief Exit point of function CanSM_Do_T_FUCO_TX_ON() */
#define DBG_CANSM_DO_T_FUCO_TX_ON_EXIT(a)
#endif

#ifndef DBG_CANSM_DO_TRY_T_FUCO_BUS_OFF_PASSIVE_ENTRY
/** \brief Entry point of function CanSM_Do_TRY_T_FUCO_BUS_OFF_PASSIVE() */
#define DBG_CANSM_DO_TRY_T_FUCO_BUS_OFF_PASSIVE_ENTRY(a)
#endif

#ifndef DBG_CANSM_DO_TRY_T_FUCO_BUS_OFF_PASSIVE_EXIT
/** \brief Exit point of function CanSM_Do_TRY_T_FUCO_BUS_OFF_PASSIVE() */
#define DBG_CANSM_DO_TRY_T_FUCO_BUS_OFF_PASSIVE_EXIT(a)
#endif

#ifndef DBG_CANSM_MAINFUNCTIONCHECKMODEINDICATIONS_ENTRY
/** \brief Entry point of function CanSM_MainFunctionCheckModeIndications() */
#define DBG_CANSM_MAINFUNCTIONCHECKMODEINDICATIONS_ENTRY(a,b,c)
#endif

#ifndef DBG_CANSM_MAINFUNCTIONCHECKMODEINDICATIONS_EXIT
/** \brief Exit point of function CanSM_MainFunctionCheckModeIndications() */
#define DBG_CANSM_MAINFUNCTIONCHECKMODEINDICATIONS_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_MAINFUNCTIONREPEATMODEREQUESTS_ENTRY
/** \brief Entry point of function CanSM_MainFunctionRepeatModeRequests() */
#define DBG_CANSM_MAINFUNCTIONREPEATMODEREQUESTS_ENTRY(a,b,c)
#endif

#ifndef DBG_CANSM_MAINFUNCTIONREPEATMODEREQUESTS_EXIT
/** \brief Exit point of function CanSM_MainFunctionRepeatModeRequests() */
#define DBG_CANSM_MAINFUNCTIONREPEATMODEREQUESTS_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_DEFAULTTRAILINGCRITICALSECTION_ENTRY
/** \brief Entry point of function CanSM_DefaultTrailingCriticalSection() */
#define DBG_CANSM_DEFAULTTRAILINGCRITICALSECTION_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_DEFAULTTRAILINGCRITICALSECTION_EXIT
/** \brief Exit point of function CanSM_DefaultTrailingCriticalSection() */
#define DBG_CANSM_DEFAULTTRAILINGCRITICALSECTION_EXIT(a,b)
#endif

#ifndef DBG_CANSM_SETPDUMODES_ENTRY
/** \brief Entry point of function CanSM_SetPduModes() */
#define DBG_CANSM_SETPDUMODES_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_SETPDUMODES_EXIT
/** \brief Exit point of function CanSM_SetPduModes() */
#define DBG_CANSM_SETPDUMODES_EXIT(a,b)
#endif

#ifndef DBG_CANSM_CLEARCTRLMODEINDANDSETMODES_ENTRY
/** \brief Entry point of function CanSM_ClearCtrlModeIndAndSetModes() */
#define DBG_CANSM_CLEARCTRLMODEINDANDSETMODES_ENTRY(a,b,c)
#endif

#ifndef DBG_CANSM_CLEARCTRLMODEINDANDSETMODES_EXIT
/** \brief Exit point of function CanSM_ClearCtrlModeIndAndSetModes() */
#define DBG_CANSM_CLEARCTRLMODEINDANDSETMODES_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_CHECKCTRLMODEINDICATIONS_ENTRY
/** \brief Entry point of function CanSM_CheckCtrlModeIndications() */
#define DBG_CANSM_CHECKCTRLMODEINDICATIONS_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_HANDLETXTIMEOUTEXCEPTION_ENTRY
/** \brief Entry point of function CanSM_HandleTxTimeoutException() */
#define DBG_CANSM_HANDLETXTIMEOUTEXCEPTION_ENTRY(a,b,c)
#endif

#ifndef DBG_CANSM_HANDLETXTIMEOUTEXCEPTION_EXIT
/** \brief Exit point of function CanSM_HandleTxTimeoutException() */
#define DBG_CANSM_HANDLETXTIMEOUTEXCEPTION_EXIT(a,b,c,d)
#endif

#ifndef DBG_CANSM_CHECKCTRLMODEINDICATIONS_EXIT
/** \brief Exit point of function CanSM_CheckCtrlModeIndications() */
#define DBG_CANSM_CHECKCTRLMODEINDICATIONS_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_SETCTRLMODES_ENTRY
/** \brief Entry point of function CanSM_SetCtrlModes() */
#define DBG_CANSM_SETCTRLMODES_ENTRY(a,b,c)
#endif

#ifndef DBG_CANSM_SETCTRLMODES_EXIT
/** \brief Exit point of function CanSM_SetCtrlModes() */
#define DBG_CANSM_SETCTRLMODES_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_CONTROLLERMODETYPETOUINT8_ENTRY
/** \brief Entry point of function CanSM_ControllerModeTypeToUint8() */
#define DBG_CANSM_CONTROLLERMODETYPETOUINT8_ENTRY(a)
#endif

#ifndef DBG_CANSM_CONTROLLERMODETYPETOUINT8_EXIT
/** \brief Exit point of function CanSM_ControllerModeTypeToUint8() */
#define DBG_CANSM_CONTROLLERMODETYPETOUINT8_EXIT(a,b)
#endif

#ifndef DBG_CANSM_CHECKCANIFGETTXCONFIRMATIONSTATES_ENTRY
/** \brief Entry point of function CanSM_CheckCanIfGetTxConfirmationStates() */
#define DBG_CANSM_CHECKCANIFGETTXCONFIRMATIONSTATES_ENTRY(a)
#endif

#ifndef DBG_CANSM_CHECKCANIFGETTXCONFIRMATIONSTATES_EXIT
/** \brief Exit point of function CanSM_CheckCanIfGetTxConfirmationStates() */
#define DBG_CANSM_CHECKCANIFGETTXCONFIRMATIONSTATES_EXIT(a,b)
#endif

#ifndef DBG_CANSM_CLEARTRCVMODEINDANDSETMODE_ENTRY
/** \brief Entry point of function CanSM_ClearTrcvModeIndAndSetMode() */
#define DBG_CANSM_CLEARTRCVMODEINDANDSETMODE_ENTRY(a,b,c)
#endif

#ifndef DBG_CANSM_CLEARTRCVMODEINDANDSETMODE_EXIT
/** \brief Exit point of function CanSM_ClearTrcvModeIndAndSetMode() */
#define DBG_CANSM_CLEARTRCVMODEINDANDSETMODE_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_CHECKTRCVMODEINDICATION_ENTRY
/** \brief Entry point of function CanSM_CheckTrcvModeIndication() */
#define DBG_CANSM_CHECKTRCVMODEINDICATION_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_CHECKTRCVMODEINDICATION_EXIT
/** \brief Exit point of function CanSM_CheckTrcvModeIndication() */
#define DBG_CANSM_CHECKTRCVMODEINDICATION_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_SETTRCVMODE_ENTRY
/** \brief Entry point of function CanSM_SetTrcvMode() */
#define DBG_CANSM_SETTRCVMODE_ENTRY(a,b,c)
#endif

#ifndef DBG_CANSM_SETTRCVMODE_EXIT
/** \brief Exit point of function CanSM_SetTrcvMode() */
#define DBG_CANSM_SETTRCVMODE_EXIT(a,b,c)
#endif

#ifndef DBG_CANSM_TRCVMODETYPETOUINT8_ENTRY
/** \brief Entry point of function CanSM_TrcvModeTypeToUint8() */
#define DBG_CANSM_TRCVMODETYPETOUINT8_ENTRY(a)
#endif

#ifndef DBG_CANSM_TRCVMODETYPETOUINT8_EXIT
/** \brief Exit point of function CanSM_TrcvModeTypeToUint8() */
#define DBG_CANSM_TRCVMODETYPETOUINT8_EXIT(a,b)
#endif

#ifndef DBG_CANSM_CLEARTRCVWUFFLAG_ENTRY
/** \brief Entry point of function CanSM_ClearTrcvWufFlag() */
#define DBG_CANSM_CLEARTRCVWUFFLAG_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_CLEARTRCVWUFFLAG_EXIT
/** \brief Exit point of function CanSM_ClearTrcvWufFlag() */
#define DBG_CANSM_CLEARTRCVWUFFLAG_EXIT(a,b)
#endif

#ifndef DBG_CANSM_CHECKTRCVWAKEFLAG_ENTRY
/** \brief Entry point of function CanSM_CheckTrcvWakeFlag() */
#define DBG_CANSM_CHECKTRCVWAKEFLAG_ENTRY(a,b)
#endif

#ifndef DBG_CANSM_CHECKTRCVWAKEFLAG_EXIT
/** \brief Exit point of function CanSM_CheckTrcvWakeFlag() */
#define DBG_CANSM_CHECKTRCVWAKEFLAG_EXIT(a,b)
#endif

#ifndef DBG_CANSM_INTERNALSTATE_GRP
#define DBG_CANSM_INTERNALSTATE_GRP(a,b,c)
#endif

#ifndef DBG_CANSM_GETNETWORKINDEXFROMHANDLE_ENTRY
/** \brief Entry point of function CanSM_GetNetworkIndexFromHandle */
#define DBG_CANSM_GETNETWORKINDEXFROMHANDLE_ENTRY(a)
#endif

#ifndef DBG_CANSM_GETNETWORKINDEXFROMHANDLE_EXIT
/** \brief Exit point of function CanSM_GetNetworkIndexFromHandle */
#define DBG_CANSM_GETNETWORKINDEXFROMHANDLE_EXIT(a,b)
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

#endif /* (!defined CANSM_TRACE_H) */
/*==================[end of file]===========================================*/
