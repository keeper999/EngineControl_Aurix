/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Dsl                                                     */
/* !Description     : Diagnostic Session Layer                                */
/*                                                                            */
/* !Module          : Dsl                                                     */
/* !Description     : Diagnostic Session Layer                                */
/*                                                                            */
/* !File            : Dcm_Dsl.c                                               */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VALEO                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791031T0/archives/B791031T0/04_Software_Component$*/
/* $Revision::   1.141.1.1$$Author::   aalaa          $$Date::   Jul 07 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file
*
* \par
*   Internals of the module DSL. \n
*   This file contains the internals of the module DSL.  */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup  Dsl_Comp_Id Dsl Component
* Diagnostic Session Layer
* \{
*/
/*! \defgroup DSL_Module_Id Dsl Module
* This is the grouping of Dsl module members.
* \{
*/
/******************************************************************************/

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#include "Dcm.h"
#include "Dcm_Internal.h"
#include "Dcm_Cbk.h"
/* PRQA L:L1                                                                  */
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
#include "BswM_Dcm.h"
#if(DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#include "SchM_Dcm.h"
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
#include "Dcm_Callouts.h"
#endif
/* PRQA L:L1                                                                  */

#if(DCM_bINTER_MOD_VER_CHECK == STD_ON)
/******************************************************************************/
/* Intermodule Version Checking                                              */
/******************************************************************************/
/* Check versus PDUR */
#ifdef PDUR_AR_RELEASE_MAJOR_VERSION
#ifdef PDUR_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (PDUR_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "PDUR AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (PDUR_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "PDUR AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "PDUR AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "PDUR AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus ComM */
#ifdef COMM_AR_RELEASE_MAJOR_VERSION
#ifdef COMM_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (COMM_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "COMM AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (COMM_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "COMM AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "COMM AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "COMM AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus BswM */
#ifdef BSWM_AR_RELEASE_MAJOR_VERSION
#ifdef BSWM_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (BSWM_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "BSWM AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (BSWM_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "BSWM AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "BSWM AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "BSWM AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus RTE */
#ifdef RTE_AR_RELEASE_MAJOR_VERSION
#ifdef RTE_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (RTE_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "RTE AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (RTE_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "RTE AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "RTE AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "RTE AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus DET */
#if(DCM_DEV_ERROR_DETECT == STD_ON)
#ifdef DET_AR_RELEASE_MAJOR_VERSION
#ifdef DET_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (DET_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "DET AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (DET_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "DET AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "DET AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "DET AR RELEASE MAJOR VERSION not defined"
#endif
#endif
/******************************************************************************/
/* Check versus COMSTACK_TYPES */
#ifdef COMSTACK_TYPES_AR_RELEASE_MAJOR_VERSION
#ifdef COMSTACK_TYPES_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (COMSTACK_TYPES_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "COMSTACK_TYPES AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (COMSTACK_TYPES_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "COMSTACK_TYPES AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "COMSTACK_TYPES AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "COMSTACK_TYPES AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus SchM */
#ifdef SCHM_AR_RELEASE_MAJOR_VERSION
#ifdef SCHM_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (SCHM_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "SCHM AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (SCHM_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "SCHM AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "SCHM AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "SCHM AR RELEASE MAJOR VERSION not defined"
#endif
#endif /* #if(DCM_bINTER_MOD_VER_CHECK == STD_ON) */

/******************************************************************************/
/* SYMBOLIC DEFINES                                                           */
/******************************************************************************/
/*! \Description  Tester Present Service ID \n
 *  \Range        0x3E */
#define u8TP_SERV_ID            (uint8)0x3E
/*! \Description  Tester Present Suppress Response Sub-function ID \n
 *  \Range        0x80 */
#define u8TP_SUBFUC_SR_ID       (uint8)0x80
/*! \Description  Internal Tx Buffer Size \n
 *  \Range        0x03 */
#define u8INT_TX_BUFF_SIZE      (uint8)0x03
/*! \Description  Diagnostic Session Control Service ID \n
 *  \Range        0x10 */
#define u8DSC_SID               (uint8)0x10
/*! \Description  ECU Reset Service ID \n
 *  \Range        0x11 */
#define u8ECU_RESET_SID         (uint8)0x11
/*! \Description  All Sessions Level \n
 *  \Range        0xFF */
#define u8ALL_SESSION_LEVEL     0xFF

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3453]: macro used for performance.        */
/* PRQA S 3453 ++                                                             */
/*! \Description  Returns Protocol Priority by Protocol Index */
#define u8PROT_PRIORITY(u8ProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].u8DcmDslProtocolPriority

/*! \Description  Returns Rx Buffer ID by Protocol Index */
#define u8RX_BUFFER_ID(u8RxProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8RxProtocolIdx].u8DcmDslProtocolRxBufferID

/*! \Description  Returns Tx Buffer ID by Protocol Index */
#define u8TX_BUFFER_ID(u8TxProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8TxProtocolIdx].u8DcmDslProtocolTxBufferID

/*! \Description  Returns Rx Protocol Index by Rx PduId */
#define u8RX_PROTOCOL_IDX(RxPduId)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRx[RxPduId].u8DcmDslProtocolIndex

/*! \Description  Returns Buffer Size by Buffer ID */
#define udtBUFFER_SIZE(u8BufferId)\
  Dcm_kstreDslConfig.astrDcmDslBuffer[u8BufferId].udtBufferSize

/*! \Description  Returns Network ID by PduId */
#define u8NETWORK_ID(udtPduId)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRx[udtPduId].u8DcmDslProtocolRxChannelId

/*! \Description  Returns Protocol ID by Protocol Index */
#define u8PROTOCOL_ID(u8ProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].u8DcmDslProtocolID

/*! \Description  Returns Session Ref by Protocol Index */
#define pkstrSESSION_REF(u8ProtocolIdx)\
  Dcm_kstreDslConfig.astrDcmDslProtocolRow[u8ProtocolIdx].\
  pkstrDcmDslProtocolSessionRef

/*! \Description  Returns Rx Addressing Type by Rx PduId */
#define u8RX_ADDR_TYPE(udtRxPduId)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRx[udtRxPduId].u8DcmDslProtocolRxAddrType

/*! \Description  Returns SID Table by Protocol Index */
#define u8SID_TABLE(u8ProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].u8DcmDslProtocolSIDTable

/*! \Description  Returns Tx Pdu Ref by RxPduId*/
#define udtTX_PDU_REF(udtRxPduId)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.pkstrDcmDslProtocolRx[udtRxPduId].\
  udtDcmDslProtocolTxPduRef

/*! \Description  Returns Protocol Index by Tx Confirmation PduId*/
#define u8PROTOCOL_IDX(udtTxConfPduId)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolTx[udtTxConfPduId].u8DcmDslProtocolIndex

/* !Deviation : Inhibit MISRA rule [3456]: Parameter is needed to be evaluated
 *              more than once.                                               */
/* PRQA S 3456 ++                                                             */
/*! \Description  Returns if the msg is Tester Present and Response Suppressed*/
#define bMSG_TP_AND_RESP_SUPP(u8RxBufferId)\
  ( (Dcm_kstreDslConfig.astrDcmDslBuffer[u8RxBufferId].pudtBuffer[0]\
     == u8TP_SERV_ID) &&\
    (Dcm_kstreDslConfig.astrDcmDslBuffer[u8RxBufferId].pudtBuffer[1]\
     == u8TP_SUBFUC_SR_ID) )
/* PRQA S 3456 --                                                             */

#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/*! \Description  Returns Preemption timeout by Protocol Index */
#define u16PREEMPT_TIMEOUT(u8ProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].u16DcmDslProtocolPreemptTimeout
#endif

/*! \Description  Returns Number of Rx Protocols */
#define u8NUM_PROTOCOL_RX()\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslNumProtocolRx

/*! \Description  Returns Number of Tx Protocols */
#define u8NUM_PROTOCOL_TX()\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslNumProtocolTx

/*! \Description  Returns Protocol Trans Type by Protocol Index */
#define u8PROT_TRANS_TYPE(u8ProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.pkstrDcmDslProtocolRow[u8ProtocolIdx].\
  u8DcmDslProtocolTransType

/*! \Description  Returns Connection Ref by Rx PduId */
#define u8CONN_REF(udtRxPduId)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.pkstrDcmDslProtocolRx[udtRxPduId].\
  u8DcmDslConnectionRef

/*! \Description  Returns P2Server time by Protocol Index */
#define u16P2_SERVER_ADJUST(u8ProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.pkstrDcmDslProtocolRow[u8ProtocolIdx].\
  u16DcmTimStrP2ServerAdjust

/*! \Description  Returns P2StarServer time by Protocol Index */
#define u16P2STAR_SERVER_ADJUST(u8ProtocolIdx)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.pkstrDcmDslProtocolRow[u8ProtocolIdx].\
  u16DcmTimStrP2StarServerAdjust

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/*! \Description Returns Periodic Protocol container pointer */
#define pkstrPERIODIC_TRANS_PTR(u8ProtocolIdx, u8ConnRef)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].ppkstrDcmDslConnection[u8ConnRef]->\
  pkstrDcmDslPeriodicTransmission

/*! \Description Returns the Periodic Protocol Index */
#define u8PERIODIC_PROT_IDX(u8ProtocolIdx, u8ConnRef)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].ppkstrDcmDslConnection[u8ConnRef]->\
  pkstrDcmDslPeriodicTransmission->u8PeriodicPrtclRowIdx

/*! \Description Returns the number of TX Confirmation PduId's of a periodic
 *               Transmission protocol */
#define u8PERIODIC_NUM_TX(u8ProtocolIdx, u8ConnRef)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].ppkstrDcmDslConnection[u8ConnRef]->\
  pkstrDcmDslPeriodicTransmission->u8NumOfTxConfirmPduIds
#endif

#if(DCM_bROE_ENABLED == STD_ON)
/*! \Description Returns the Roe protocol container pointer */
#define pkstrROE_PTR(u8ProtocolIdx, u8ConnRef)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].ppkstrDcmDslConnection[u8ConnRef]->\
  pkstrDcmDslResponseOnEvent

/*! \Description Returns the Roe protocol index */
#define u8ROE_PROT_IDX(u8ProtocolIdx, u8ConnRef)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.\
  pkstrDcmDslProtocolRow[u8ProtocolIdx].ppkstrDcmDslConnection[u8ConnRef]->\
  pkstrDcmDslResponseOnEvent->u8RoeProtocolRowIndex

/*! \Description Returns the Roe TX Confirmation PduId */
#define udtROE_TX_CONF_PDUID(u8ProtocolIdx, u8ConnRef)\
  Dcm_pkstrePbConfig->strPbDcmDslConfig.pkstrDcmDslProtocolRow[u8ProtocolIdx].\
  ppkstrDcmDslConnection[u8ConnRef]->pkstrDcmDslResponseOnEvent->\
  udtDcmDslTxConfirmPduId
#endif
/* Dcm143 */
/*! \Description  Returns S3Server time */
#define u16S3_COUNT     (uint16)((uint16)5000/DCM_TASK_TIME_IN_MS)
/* PRQA S 3453 --                                                             */

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/******************************************************************************/
/*! \Description Main Protocol Status Type. \n\n
    \Range       u8ST_MN_PROT_BOOT_LDR_CHECK,u8ST_MN_PROT_IDLE, \n
                 u8ST_MN_PROT_COPYING_RX_DATA,u8ST_MN_PROT_PROCESSING, \n
                 u8ST_MN_PROT_TX_IN_PROGRESS,u8ST_MN_PROT_TX_PENDING, \n
                 u8ST_MN_PROT_TX_GR_IN_PROGRESS, \n
                 u8ST_MN_PROT_TX_CNC_IN_PROGRESS, \n
                 u8ST_MN_PROT_TX_BT_LDR_IN_PROGRESS, \n
                 u8ST_MN_PROT_WAIT_CANCEL_RX, \n
                 u8ST_MN_PROT_WAIT_CANCEL_TX, \n
                 u8ST_MN_PROT_WAIT_CANCEL_INT_TX
*******************************************************************************/
typedef uint8 tu8MnProtStatusType;
/*! \Description  Main protocol status Boot Loader Check \n
 *  \Range        0 */
#define u8ST_MN_PROT_BOOT_LDR_CHECK      (uint8)0
/*! \Description  Main protocol status Idle \n
 *  \Range        1 */
#define u8ST_MN_PROT_IDLE                (uint8)1
/*! \Description  Main protocol status Copying Rx Data \n
 *  \Range        2 */
#define u8ST_MN_PROT_COPYING_RX_DATA     (uint8)2
/*! \Description  Main protocol status Request Processing \n
 *  \Range        3 */
#define u8ST_MN_PROT_PROCESSING          (uint8)3
/*! \Description  Main protocol status Tx In Progress \n
 *  \Range        4 */
#define u8ST_MN_PROT_TX_IN_PROGRESS      (uint8)4
/*! \Description  Main protocol status Tx Pending \n
 *  \Range        5 */
#define u8ST_MN_PROT_TX_PENDING          (uint8)5
/*! \Description  Main protocol status General Reject NRC Tx Pending \n
 *  \Range        6 */
#define u8ST_MN_PROT_GR_TX_PENDING       (uint8)6
/*! \Description  Main protocol status Tx GeneralReject In Progress \n
 *  \Range        7 */
#define u8ST_MN_PROT_TX_GR_IN_PROGRESS   (uint8)7
/*! \Description  Main protocol status Tx ConditionNotCorrect In Progress \n
 *  \Range        8 */
#define u8ST_MN_PROT_TX_CNC_IN_PROGRESS  (uint8)8
/*! \Description  Main protocol status Tx Boot Loader In Progress \n
 *  \Range        9 */
#define u8ST_MN_PROT_TX_BT_LDR_IN_PROGRESS      (uint8)9
/*! \Description  Main protocol status Waiting for Rx Cancellation \n
 *  \Range        10 */
#define u8ST_MN_PROT_WAIT_CANCEL_RX             (uint8)10
/*! \Description  Main protocol status Waiting for Tx Cancellation \n
 *  \Range        11 */
#define u8ST_MN_PROT_WAIT_CANCEL_TX             (uint8)11
/*! \Description  Main protocol status Waiting for internal Tx Cancellation \n
 *  \Range        12 */
#define u8ST_MN_PROT_WAIT_CANCEL_INT_TX         (uint8)12
/*! \Description  Main protocol status Waiting for TxConfirmation to end the
 *                main process \n
 *  \Range        13 */
#define u8ST_MN_PROT_WAIT_TO_END_PRCS           (uint8)13
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/*! \Description  Main protocol status Paged Buffer Processed \n
 *  \Range        14 */
#define u8ST_MN_PROT_PAGE_DATA_PROCESSED        (uint8)14
/*! \Description  Main protocol status Page Update Requested \n
 *  \Range        15 */
#define u8ST_MN_PROT_PAGE_UPDATE_REQUESTED      (uint8)15
/*! \Description  Main protocol status Page TX pending \n
 *  \Range        16 */
#define u8ST_MN_PROT_PAGE_TX_PENDING            (uint8)16
#endif
/*! \Description  Main protocol status Send General Reject \n
 *  \Range        17 */
#define u8ST_MN_PROT_SEND_GR                    (uint8)17


#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Preempting Protocol Status Type. \n\n
    \Range       u8ST_PREEMPT_PROT_IDLE,u8ST_PREEMPT_PROT_COPYING_RX_DATA, \n
                 u8ST_PREEMPT_PROT_TX_IN_PROGRESS, \n
                 u8ST_PREEMPT_PROT_TX_CNC_IN_PROGRESS
*******************************************************************************/
typedef uint8 tu8PreempProtStatusType;
/*! \Description  Preempting protocol status Idle \n
 *  \Range        0 */
#define u8ST_PREEMPT_PROT_IDLE                 (uint8)0
/*! \Description  Preempting protocol status Copying Rx Data \n
 *  \Range        1 */
#define u8ST_PREEMPT_PROT_COPYING_RX_DATA      (uint8)1
/*! \Description  Preempting protocol status Tx In Progress \n
 *  \Range        2 */
#define u8ST_PREEMPT_PROT_TX_IN_PROGRESS       (uint8)2
/*! \Description  Preempting protocol status Tx ConditionNotCorrect 
                  In Progress \n
 *  \Range        3 */
#define u8ST_PREEMPT_PROT_TX_CNC_IN_PROGRESS   (uint8)3
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Periodic Protocol Status Type. \n\n
    \Range       u8ST_PERIODIC_PROT_IDLE,u8ST_PERIODIC_PROT_PROCESSING, \n
                 u8ST_PERIODIC_PROT_TX_IN_PROGRESS, \n
                 u8ST_PERIODIC_PROT_PROCESS_PENDING
*******************************************************************************/
typedef uint8 tu8PeriodProtStatusType;
/*! \Description  Periodic protocol status Idle \n
 *  \Range        0 */
#define u8ST_PERIODIC_PROT_IDLE                   (uint8)0
/*! \Description  Periodic protocol status Processing \n
 *  \Range        1 */
#define u8ST_PERIODIC_PROT_PROCESSING             (uint8)1
/*! \Description  Periodic protocol status TX In Progress \n
 *  \Range        2 */
#define u8ST_PERIODIC_PROT_TX_IN_PROGRESS         (uint8)2
/*! \Description  Periodic protocol status Processing Pending \n
 *  \Range        3 */
#define u8ST_PERIODIC_PROT_PROCESS_PENDING        (uint8)3
/*! \Description  Periodic protocol status Waiting TX Cancellation \n
 *  \Range        4 */
#define u8ST_PERIODIC_PROT_WAIT_CANCEL_TX         (uint8)4
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/*! \Description  Periodic protocol status Page Processed \n
 *  \Range        5 */
#define u8ST_PERIODIC_PROT_PAGE_DATA_PROCESSED    (uint8)5
/*! \Description  Periodic protocol status Page Update Requested \n
 *  \Range        6 */
#define u8ST_PERIODIC_PROT_PAGE_UPDATE_REQUESTED  (uint8)6
#endif
#endif

#if(DCM_bROE_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Roe Protocol Status Type. \n\n
    \Range       u8ST_ROE_PROT_IDLE,u8ST_ROE_PROT_PROCESSING, \n
                 u8ST_ROE_PROT_TX_IN_PROGRESS, \n
                 u8ST_ROE_PROT_PROCESS_PENDING
*******************************************************************************/
typedef uint8 tu8RoeProtStatusType;
/*! \Description  Roe protocol status Idle \n
 *  \Range        0 */
#define u8ST_ROE_PROT_IDLE                   (uint8)0
/*! \Description  Roe protocol status Processing \n
 *  \Range        1 */
#define u8ST_ROE_PROT_PROCESSING             (uint8)1
/*! \Description  Roe protocol status TX In Progress \n
 *  \Range        2 */
#define u8ST_ROE_PROT_TX_IN_PROGRESS         (uint8)2
/*! \Description  Roe protocol status Processing Pending \n
 *  \Range        3 */
#define u8ST_ROE_PROT_PROCESS_PENDING        (uint8)3
/*! \Description  Roe protocol status Waiting TX cancellation \n
 *  \Range        4 */
#define u8ST_ROE_PROT_WAIT_CANCEL_TX         (uint8)4
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/*! \Description  Roe protocol status Page Processed \n
 *  \Range        5 */
#define u8ST_ROE_PROT_PAGE_DATA_PROCESSED    (uint8)5
/*! \Description  Roe protocol status Page Update Requested \n
 *  \Range        6 */
#define u8ST_ROE_PROT_PAGE_UPDATE_REQUESTED  (uint8)6
#endif
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
/*! \Description  Roe protocol status Pending for Queuing \n
 *  \Range        7 */
#define u8ST_ROE_PROT_PEND_QUE               (uint8)7
#endif
#endif

/******************************************************************************/
/*! \Description Buffer Lock Status Type. \n
    \Range       u8ST_BUFF_FREE,u8ST_BUFF_LOCKED
*******************************************************************************/
typedef boolean tbBufferStatusType;
/*! \Description  Buffer status Free \n
 *  \Range        0 */
#define u8ST_BUFF_FREE                 (uint8)0
/*! \Description  Buffer status Locked \n
 *  \Range        1 */
#define u8ST_BUFF_LOCKED               (uint8)1

typedef struct {
  /*! \Description  Buffer Index \n
   *  \Range        0..4294967295 */
  Dcm_MsgLenType udtIndex;
  /*! \Description  Buffer Status \n
   *  \Range        [u8ST_BUFF_FREE, u8ST_BUFF_LOCKED] */
  tbBufferStatusType udtStatus;
}tstrBufferInfoType;

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
typedef struct {
  /*! \Description  Periodic Protocol Status \n
   *  \Range        Range of type tu8PeriodProtStatusType */
  tu8PeriodProtStatusType udtProtStatus;
  /*! \Description  Periodic Protocol Message Context \n
   *  \Range        NA */
  Dcm_MsgContextType udtMsgContext;
  /*! \Description  Periodic Protocol TxPduRef \n
   *  \Range        Range of type PduIdType */
  PduIdType udtPeriodicTxPduRef;
  /*! \Description  Periodic Protocol Index \n
   *  \Range        0..255 */
  uint8     u8PeriodicProtIndex;
}tstrPeriodicProtType;
#endif

#if(DCM_bROE_ENABLED == STD_ON)
typedef struct {
  /*! \Description  Roe Protocol Status \n
   *  \Range        Range of type tu8RoeProtStatusType */
  tu8RoeProtStatusType udtProtStatus;
  /*! \Description  Roe Protocol Message Context \n
   *  \Range        NA */
  Dcm_MsgContextType udtMsgContext;
  PduIdType udtRoeTxPduRef;
  /*! \Description  Roe Protocol Index \n
   *  \Range        0..255 */
  uint8 u8RoeProtIndex;
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
  /*! \Description  Roe Event Enabling status \n
   *  \Range        TRUE,FALSE */
  boolean bIsQueued;
#endif
}tstrRoeProtType;

#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
typedef struct {
  /*! \Description  TxPduRef of the queued Roe response \n
   *  \Range        Range of type PduIdType */
  PduIdType udtRoeTxPduRef;
  /*! \Description  PduInfo of the queued Roe response \n
   *  \Range        Range of type PduInfoType */
  PduInfoType udtTxPduInfo;
  /*! \Description  udtRxPduId of the queued Roe response \n
   *  \Range        Range of type PduIdType */
  PduIdType udtRxPduId;
}tstrRoeTxQueType;
#endif
#endif
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */

/* !Deviation : Inhibit MISRA rule [3406]: Message is generated 
                mistakenly due to QAC Bug   */
/* PRQA S 3406 L1 */

/*  \Trace_To    CDD-DSL-0004(0)    */

/***********************  DCM_START_SEC_VAR_8BIT ******************************/
#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"

#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/*! \Description Preempt Protocol Index \n */
/*! \Range       0..255    */
static VAR(uint8, DCM_VAR) Dsl_u8PreemptProtocolIndex;
/*! \Description Preempt Protocol Status \n
    \Range       u8ST_PREEMPT_PROT_IDLE,u8ST_PREEMPT_PROT_COPYING_RX_DATA, \n
                 u8ST_PREEMPT_PROT_TX_IN_PROGRESS, \n
                 u8ST_PREEMPT_PROT_TX_CNC_IN_PROGRESS */
static VAR(tu8PreempProtStatusType, DCM_VAR) Dsl_u8PreemptProtStatus;
#endif
/*! \Description Main Protocol Status \n
    \Range       u8ST_MN_PROT_BOOT_LDR_CHECK,u8ST_MN_PROT_IDLE, \n
                 u8ST_MN_PROT_COPYING_RX_DATA,u8ST_MN_PROT_PROCESSING, \n
                 u8ST_MN_PROT_TX_IN_PROGRESS,u8ST_MN_PROT_TX_PENDING, \n
                 u8ST_MN_PROT_TX_GR_IN_PROGRESS, \n
                 u8ST_MN_PROT_TX_CNC_IN_PROGRESS, \n
                 u8ST_MN_PROT_TX_BT_LDR_IN_PROGRESS, \n
                 u8ST_MN_PROT_WAIT_CANCEL_RX, \n
                 u8ST_MN_PROT_WAIT_CANCEL_TX        */
static VAR(tu8MnProtStatusType,DCM_VAR) Dsl_u8MainProtocolStatus;
/*! \Description Number of sent Response Pending \n
    \Range       0..255       */
static VAR(uint8,DCM_VAR) Dsl_u8RespPendCount;
/* Dcm020, Dcm507 */

/*! \Description Current Security Level \n
    \Range       0..255 \n
    \Trace_To    CDD-1160(0)    */
VAR(Dcm_SecLevelType, DCM_VAR) Dcm_u8eCurrSecLevel;
/* Dcm022, Dcm508 */
/*! \Description Current Session Control \n
    \Range       0..255 \n
    \Trace_To    CDD-1161(0)   */
VAR(Dcm_SesCtrlType, DCM_VAR)  Dcm_u8eCurrSesCtrl;
/* Dcm509 */
/*! \Description Main Protocol Index \n
    \Range       0..255 \n
    \Trace_To    CDD-1162(0)  */
static VAR(uint8,DCM_VAR) Dsl_u8MainProtocolIndex;
/*! \Description Main Protocol ID \n
    \Range       0..255       */
VAR(uint8,DCM_VAR) Dcm_u8eMainProtocolID;

#if(DCM_bROE_ENABLED == STD_ON)
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
/*! \Description Roe Transmission Retry Counter \n
    \Range       0..255       */
static VAR(uint8,DCM_VAR) Dsl_u8RoeRetryCounter;
#endif
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/*! \Description Periodic Id of pending periodic transmission \n
    \Range       0..255       */
static VAR(uint8,DCM_VAR) Dsl_u8PendingPeriodicId;
#endif

#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"
/******************************************************************************/

/***********************  DCM_START_SEC_VAR_16BIT *****************************/
#define DCM_START_SEC_VAR_16BIT
#include "MemMap.h"

#if(DCM_bROE_ENABLED == STD_ON)
/*! \Description Counter of Roe Inter-Message time \n
    \Range       0..65535  \n
    \Trace_To    CDD-DSL-0043(0)     */
static VAR(uint16, DCM_VAR) Dsl_u16RoeInterMsgCounter;
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
/*! \Description Roe queue Rear Index \n
    \Range       0..65535       */
static VAR(uint16, DCM_VAR) Dsl_u16RoeQueRear;
/*! \Description Roe queue Front Index \n
    \Range       0..65535       */
static VAR(uint16, DCM_VAR) Dsl_u16RoeQueFront;
#endif
#endif
/*! \Description P2Server Counter \n
    \Range       0..65535 \n
    \Trace_To    CDD-DSL-0005(0)  */
static VAR(uint16,DCM_VAR) Dsl_u16P2Counter;
/*! \Description S3 Counter \n
    \Range       0..65535 \n
    \Trace_To    CDD-DSL-0006(0)  */
static VAR(uint16,DCM_VAR) Dsl_u16S3Counter;
/*! \Description S3 Reload Time \n
    \Range       0..65535 \n
    \Trace_To    CDD-DSL-0007(0)       */
static VAR(uint16,DCM_VAR) Dsl_u16S3Reload;
/*! \Description P2Server Reload Time \n
    \Range       0..65535 \n
    \Trace_To    CDD-DSL-0008(0)       */
static VAR(uint16,DCM_VAR) Dsl_u16P2Reload;
/*! \Description P2StarServer Reload Time \n
    \Range       0..65535 \n
    \Trace_To    CDD-DSL-0009(0)       */
static VAR(uint16,DCM_VAR) Dsl_u16P2StarReload;
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/*! \Description Preemption Timeout Counter \n
    \Range       0..65535 */
static VAR(uint16,DCM_VAR) Dsl_u16PreemptTimeoutCtr;
#endif
/*! \Description P2Server Adjust Time \n
    \Range       0..65535 \n
    \Trace_To    CDD-DSL-0010(0)       */
static VAR(uint16,DCM_VAR) Dsl_u16P2Adjust;

#define DCM_STOP_SEC_VAR_16BIT
#include "MemMap.h"
/******************************************************************************/

/*********************  DCM_START_SEC_VAR_BOOLEAN *****************************/
#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
/*! \Description Main Protocol Started Flag \n
    \Range       [TRUE,FALSE]       */
static VAR(boolean,DCM_VAR) Dsl_bMainProtStarted;
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/*! \Description Preemption Timeout On Flag \n
    \Range       [TRUE,FALSE]       */
static VAR(boolean,DCM_VAR) Dsl_bPreemptTimeoutOn;
#endif
/*! \Description Internal Tx In Progress Flag \n
    \Range       [TRUE,FALSE]       */
static VAR(boolean,DCM_VAR) Dsl_bIntTxInProgress;
/*! \Description Forced RCRRP In Progress Flag \n
    \Range       [TRUE,FALSE]       */
static VAR(boolean,DCM_VAR) Dsl_bFrcdRCRRPInProgress;
/*! \Description General Reject NRC TX Pending Flag \n
    \Range       [TRUE,FALSE]       */
static VAR(boolean,DCM_VAR) Dsl_bGeneralRejectPend;
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/*! \Description Preemption in progress Flag \n
    \Range       [TRUE,FALSE]       */
static VAR(boolean,DCM_VAR) Dsl_bPreemptionInProgress;
#endif
/* Dcm506 */
/*! \Description Diagnostics Active Flag \n
    \Range       [TRUE,FALSE] \n
    \Trace_To    CDD-1159(0)  */
VAR(boolean, DCM_VAR) Dcm_beDiagnosticsActive;
#if((DCM_bROE_ENABLED == STD_ON)&&(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON))
/*! \Description Roe Transmissions Queue Status \n
    \Range       [TRUE,FALSE] \n
    \Trace_To    CDD-DSL-0044(0)   */
static VAR(tbBufferStatusType, DCM_VAR) Dsl_bRoeTransQueStatus;
#endif
#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"
/******************************************************************************/

/*******************  DCM_START_SEC_VAR_UNSPECIFIED ***************************/
#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/*! \Description Preemting Rx PduId \n
    \Range       0..65535 */
static VAR(PduIdType,DCM_VAR) Dsl_udtPreemptRxPduId;
#endif
/*! \Description Main Protocol Msg Context \n
 *  \Trace_To    CDD-DSL-0014(0)  */
static VAR(Dcm_MsgContextType,DCM_VAR) Dsl_strMainProtMsgContext;
/*! \Description Main Protocol Rx PduId \n
    \Range       0..65535 \n
    \Trace_To    CDD-DSL-0011(0)   */
static VAR(PduIdType,DCM_VAR)          Dsl_udtMainProtRxPduId;
/*! \Description Buffer Info \n
    \Trace_To  CDD-DSL-0012(0), CDD-DSL-0013(0) */
static VAR(tstrBufferInfoType,DCM_VAR)
                                    Dsl_astrBufferInfo[DCM_u8NUMBER_OF_BUFFERS];
/*! \Description Internal Buffer \n
    \Range       0..255       */
static VAR(uint8,DCM_VAR) Dsl_au8InternalTxBuffer[u8INT_TX_BUFF_SIZE];

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
/*! \Description Programming Conditions */
static VAR(Dcm_ProgConditionsType,DCM_VAR) Dsl_strProgConditions;
#endif

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
static VAR(Dcm_MsgLenType,DCM_VAR)     Dsl_udtMainFilledPageLen;
static VAR(Dcm_MsgLenType,DCM_VAR)     Dsl_udtMnTotalPageCopiedLen;
static VAR(Dcm_MsgLenType,DCM_VAR)     Dsl_udtMnPageResidueBuffIdx;
/* !Deviation : Inhibit MISRA rule [3218]: This static variable is used
 *              in one function                                               */
/* PRQA S 3218 ++ */
static VAR(uint8,DCM_VAR) Dsl_au8MnPageResidueBuffer[DCM_udtMAX_TX_BUFFER_SIZE];
/* PRQA S 3218 -- */
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/* Dcm081 */
/*! \Description Periodic Protocols Info Array (parallel periodic
 *               transmissions) \n
    \Range       NA       */
static VAR(tstrPeriodicProtType, DCM_VAR)
                               Dsl_astrPeriodicProt[DCM_u8MAX_NUM_PERIODIC_TX];
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
static VAR(Dcm_MsgLenType,DCM_VAR)
    Dsl_audtPeriodFilledPageLen[DCM_u8MAX_NUM_PERIODIC_TX];
static VAR(Dcm_MsgLenType,DCM_VAR)
    Dsl_audtPeriodTotalPageCopiedLen[DCM_u8MAX_NUM_PERIODIC_TX];
static VAR(Dcm_MsgLenType,DCM_VAR)
    Dsl_audtPeriodPageResidueBuffIdx[DCM_u8MAX_NUM_PERIODIC_TX];
/* !Deviation : Inhibit MISRA rule [3218]: This static variable is used
 *              in one function                                               */
/* PRQA S 3218 ++ */
static VAR(uint8,DCM_VAR)
    Dsl_au8PeriodPageResidueBuff[DCM_u8MAX_NUM_PERIODIC_TX]
                                [DCM_udtMAX_TX_BUFFER_SIZE];
/* PRQA S 3218 -- */
#endif
#endif

#if(DCM_bROE_ENABLED == STD_ON)
/* Dcm081 */
/*! \Description Roe Protocol Info \n
    \Range       NA       */
static VAR(tstrRoeProtType, DCM_VAR) Dsl_strRoeProt;
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
/* Dcm608 */
/*! \Description Roe Transmission Queue Info \n
    \Range       NA       */
static VAR(tstrRoeTxQueType, DCM_VAR)
                     Dsl_audtRoeTransQueueInfo[DCM_u16DSP_ROE_MAX_QUEUE_LENGTH];
/* !Deviation : Inhibit MISRA rule [3218]: This static variable is used
 *              in one function and pointed by a pointer in another function  */
/* PRQA S 3218 ++ */
/* Dcm604 */
/*! \Description Roe Transmission Queue \n
    \Range       NA       */
static VAR(uint8, DCM_VAR) Dsl_au8RoeTransQueue[DCM_u16ROE_QUE_MAX_DATA_LEN];
/* PRQA S 3218 -- */
#endif
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
static VAR(Dcm_MsgLenType,DCM_VAR)     Dsl_udtRoeFilledPageLen;
static VAR(Dcm_MsgLenType,DCM_VAR)     Dsl_udtRoeTotalPageCopiedLen;
static VAR(Dcm_MsgLenType,DCM_VAR)     Dsl_udtRoePageResidueBuffIdx;
/* !Deviation : Inhibit MISRA rule [3218]: This static variable is used
 *              in one function                                               */
/* PRQA S 3218 ++ */
static VAR(uint8,DCM_VAR)
    Dsl_au8RoePageResidueBuffer[DCM_udtMAX_TX_BUFFER_SIZE];
/* PRQA S 3218 -- */
#endif
#endif

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTIONS DECLARATION                                                */
/******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"

/* Mandatory functions */
static FUNC(void, DCM_CODE) vidStMainIdle(void);
static FUNC(void, DCM_CODE) vidEndOfMainMsgExec(void);
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(BufReq_ReturnType, DCM_CODE) udtMnIdleStartOfReception(
    PduIdType udtDcmRxPduId,
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) pbProtocolPreempt);
#else
static FUNC(BufReq_ReturnType, DCM_CODE) udtMnIdleStartOfReception(
    PduIdType udtDcmRxPduId);
#endif
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(BufReq_ReturnType, DCM_CODE) udtMnActiveStartOfReception(
    PduIdType udtDcmRxPduId,
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) pbProtocolPreempt);
#else
static FUNC(BufReq_ReturnType, DCM_CODE) udtMnActiveStartOfReception(
    PduIdType udtDcmRxPduId);
#endif
static FUNC(void, DCM_CODE) vidMainRxIndication(
    PduIdType udtDcmRxPduId,
    PduIdType udtMainProtRxPduId,
    NotifResultType udtResult);
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidPreemptRxIndication(
    PduIdType udtDcmRxPduId,
    PduIdType udtMainProtRxPduId,
    NotifResultType udtResult);
static FUNC(void, DCM_CODE) vidStartProtocol(
    PduIdType udtDcmRxPduId,
    PduIdType udtMainProtRxPduId);
static FUNC(void, DCM_CODE) vidSwitchProtocol(
    PduIdType udtDcmRxPduId,
    PduIdType udtMainProtRxPduId);
#endif
static FUNC(void, DCM_CODE) vidMainProcessingDone(PduIdType udtMainProtRxPduId);
static FUNC(BufReq_ReturnType, DCM_CODE) udtMainCopyFromTxBuffer(
    PduIdType DcmTxPduId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(BufReq_ReturnType, DCM_CODE) udtPreemptCopyFromTxBuffer(
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
static FUNC(void, DCM_CODE) vidExecutePreemption(void);
static FUNC(void, DCM_CODE) vidCancelMainContext(void);
static FUNC(void, DCM_CODE) vidEndOfPreemptMsgExec(void);
#endif
static FUNC(void, DCM_CODE) vidReloadSessionTimers(
    uint8 u8ProtocolIdx,
    Dcm_SesCtrlType udtSesCtrlType);
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidHandlePreemptTimeout(void);
static FUNC(void, DCM_CODE) vidEndPreemptionProcess(void);
static FUNC(Std_ReturnType, DCM_CODE) udtAllContextsIdle(void);
#endif
static FUNC(void, DCM_CODE) vidMonitorCurrSession(void);
static FUNC(void, DCM_CODE) vidSendNrcResponsePend(void);
static FUNC(Std_ReturnType, DCM_CODE) udtNrcResponsePendAllowed(void);
static FUNC(void, DCM_CODE) vidSendGeneralReject(void);
static FUNC(Std_ReturnType, DCM_CODE) udtNrcGeneralRejectAllowed(void);
static FUNC(void, DCM_CODE) vidHandleBusyResponses(void);
static FUNC(void, DCM_CODE) vidSendNrcCondNotCorr(
    uint8 u8ProtocolIdx,
    PduIdType udtRxPduId);
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidSendNrcBusyRepeatReq(void);
#endif
static FUNC(void, DCM_CODE) vidPrepMnProtMsgContext(void);
static FUNC(Std_ReturnType, DCM_CODE) u8StartProtocol(uint8 u8ProtocolIdx);
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(Std_ReturnType, DCM_CODE) u8StopProtocol(uint8 u8ProtocolIdx);
#endif
static FUNC(void, DCM_CODE) vidSendForcedNrcResponsePend(void);
static FUNC(void, DCM_CODE) vidMainTxPendTxConfirmation(
    PduIdType udtMainProtRxPduId);
static FUNC(void, DCM_CODE) vidMainProcessingTxConfirmation(
    PduIdType udtMainProtRxPduId,
    NotifResultType udtResult);
static FUNC(void, DCM_CODE) vidMainTxConfirmation(
    NotifResultType udtResult);

/* Boot-loader functions */
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
static FUNC(void, DCM_CODE) vidStMainBootloaderCheck(void);
static FUNC(void, DCM_CODE) vidEndOfBootloaderExec(void);
static FUNC(void, DCM_CODE) vidSendBootloaderResponse(void);
#endif

/* Paged Buffer functions */
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidMainProcessPage(Dcm_MsgLenType udtFilledPageLen);
static FUNC(BufReq_ReturnType, DCM_CODE) udtMainPageCopyFromTxBuffer(
    PduIdType DcmTxPduId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
static FUNC(void, DCM_CODE) vidMainPageCopyData(
    uint8 u8TxBufferId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    PduLengthType udtCopiedDataLen);
#endif

/* ROE or Periodic functions */
#if((DCM_bROE_ENABLED == STD_ON) || (DCM_bPERIODIC_TRANS_ENABLED == STD_ON))
static FUNC(void, DCM_CODE) vidMainIdleTxConfirmation(
    NotifResultType udtResult);
#endif

/* ROE functions */
#if(DCM_bROE_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidRoeProcessingDone(void);
static FUNC(BufReq_ReturnType, DCM_CODE) udtRoeCopyFromTxBuffer(
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
static FUNC(void, DCM_CODE) vidCancelRoeContext(void);
static FUNC(void, DCM_CODE) vidHandleTyp1RoeTx(void);
static FUNC(void, DCM_CODE) vidRoeTxConfirmation(
    PduIdType udtDcmTxPduId,
    NotifResultType udtResult);
static FUNC(void, DCM_CODE) vidEndOfRoeMsgExec(void);
/* ROE Paged Buffer functions */
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidRoeProcessPage(Dcm_MsgLenType udtFilledPageLen);
static FUNC(BufReq_ReturnType, DCM_CODE) udtRoePageCopyFromTxBuffer(
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
static FUNC(void, DCM_CODE) vidRoeCopyData(
    uint8 u8TxBufferId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    PduLengthType udtCopiedDataLen);
#endif
/* ROE Queue functions */
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidQueueRoeResponse(
    P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) pudtPduInfo);
static FUNC(void, DCM_CODE) vidSendRoeQuedResponses(void);
#endif
#endif

/* Periodic functions */
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidPeriodicProcessingDone(
    Dcm_IdContextType udtIdContext);
static FUNC(BufReq_ReturnType, DCM_CODE) udtPeriodicCopyFromTxBuffer(
    uint8 u8PeriodicProtArrIdx,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
static FUNC(void, DCM_CODE) vidCancelPeriodicContext(void);
static FUNC(Std_ReturnType, DCM_CODE) udtGetFreePeriodicTxIdx(
    uint8* pu8FreePeriodicTxIdx);
static FUNC(void, DCM_CODE) vidHandleTyp1PeriodicTx(void);
static FUNC(Std_ReturnType, DCM_CODE) udtPeriodicTxTyp1Active(void);
static FUNC(Std_ReturnType, DCM_CODE) udtIsPeriodicTxPduRef(
    PduIdType DcmTxPduId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) pu8PeriodicProtIdx);
static FUNC(void, DCM_CODE) vidPeriodicTxConfirmation(
    PduIdType udtDcmTxPduId,
    NotifResultType udtResult);
static FUNC(void, DCM_CODE) vidEndOfPeriodicMsgExec(
    uint8 u8PeriodicProtArrIdx);
/* Periodic Paged Buffer functions */
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
static FUNC(void, DCM_CODE) vidPeriodicProcessPage(
    Dcm_IdContextType udtIdContext,
    Dcm_MsgLenType udtFilledPageLen);
static FUNC(BufReq_ReturnType, DCM_CODE) udtPeriodicPageCopyFromTxBuffer(
    uint8 u8PeriodicProtArrIdx,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
static FUNC(void, DCM_CODE) vidPeriodicCopyData(
    uint8 u8PeriodicProtArrIdx,
    uint8 u8TxBufferId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    PduLengthType udtCopiedDataLen);
#endif
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
/******************************************************************************/
/*! \Description Handle main protocol state u8ST_MN_PROT_BOOT_LDR_CHECK
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidStMainBootloaderCheck(void)
{
  Dcm_EcuStartModeType udtEcuStartMode;

  /*! Id ProgConditions is WARM START*/
  /* Dcm536 */
  udtEcuStartMode = Dcm_GetProgConditions(&Dsl_strProgConditions);
  if(udtEcuStartMode == DCM_WARM_START)
  {
    /*! Activate Diagnostics */
    ComM_DCM_ActiveDiagnostic(u8NETWORK_ID(Dsl_strProgConditions.udtPduId));
    Dcm_beDiagnosticsActive = TRUE;
    /*! Send Boot loader Response */
    vidSendBootloaderResponse();
  }
  /*! Else */
  else
  {
    /*! Set main state to IDLE */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_IDLE;
    /*! Call vidStMainIdle() */
    vidStMainIdle();
  }
}
#endif
/******************************************************************************/
/*! \Description Handle main protocol state u8ST_MN_PROT_IDLE
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidStMainIdle(void)
{
  /*! Call vidMonitorCurrSession() */
  /* Dcm141 */
  vidMonitorCurrSession();
  #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
  /* Handle pending TYPE 1 Periodic Transmissions. */ /* Dcm121 */
  vidHandleTyp1PeriodicTx();
  #endif
  #if(DCM_bROE_ENABLED == STD_ON)
  /*! Call vidHandleTyp1RoeTx() to handle pending TYPE 1 Roe Transmission
      which is pending on the completion of the main protocol transmission */
  /* Dcm129 */
  vidHandleTyp1RoeTx();
  #endif
}
/******************************************************************************/
/*! \Description Start of reception when main protocol is idle
    \return BUFREQ_OK: starting reception is done successfully
            BUFREQ_E_NOT_OK: starting reception fails
 *  \param[in] udtDcmRxPduId RxPduId of the protocol  \n
 *  \Range     0..65535 \n
 *  \param[in] pbProtocolPreempt Pointer to a preemption flag \n
 *  \Range     TRUE, FALSE \n
    \Trace_To  CDD-0891(0)
*******************************************************************************/
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(BufReq_ReturnType, DCM_CODE) udtMnIdleStartOfReception(
    PduIdType udtDcmRxPduId,
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) pbProtocolPreempt)
#else
static FUNC(BufReq_ReturnType, DCM_CODE) udtMnIdleStartOfReception(
    PduIdType udtDcmRxPduId)
#endif
{
  uint8             u8RxProtocolIndex;
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
  uint8             u8RxProtocolPriority;
#endif
  BufReq_ReturnType enuReturn = BUFREQ_OK;

  u8RxProtocolIndex = u8RX_PROTOCOL_IDX(udtDcmRxPduId);
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
  u8RxProtocolPriority = u8PROT_PRIORITY(u8RxProtocolIndex);
#endif

  /*! If the new protocol is not the same as the current main protocol */
  if(u8RxProtocolIndex != Dsl_u8MainProtocolIndex)
  {
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
    /*! If the new protocol is more prior to the current main or the
     *  current session is the default */
    if((u8RxProtocolPriority < u8PROT_PRIORITY(Dsl_u8MainProtocolIndex))
     ||(Dcm_u8eCurrSesCtrl == DCM_DEFAULT_SESSION))
    {
      /* Dcm625 */
      /*! Set the preempt flag */
      *pbProtocolPreempt = TRUE;
    }
    /*! Else */
    else
    {
#endif
      /*! Set the return value to BUFREQ_E_NOT_OK */
      enuReturn = BUFREQ_E_NOT_OK; /* Dcm655 */
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
    }
#endif
  }

  return enuReturn;
}
/******************************************************************************/
/*! \Description Start of reception when main protocol is not idle
    \return BUFREQ_OK: starting reception is done successfully
            BUFREQ_E_NOT_OK: starting reception fails
 *  \param[in] udtDcmRxPduId RxPduId of the protocol  \n
 *  \Range     0..65535 \n
 *  \param[in] pbProtocolPreempt Pointer to a preemption flag \n
 *  \Range     TRUE, FALSE \n
*******************************************************************************/
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
static FUNC(BufReq_ReturnType, DCM_CODE) udtMnActiveStartOfReception(
    PduIdType udtDcmRxPduId,
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) pbProtocolPreempt)
#else
static FUNC(BufReq_ReturnType, DCM_CODE) udtMnActiveStartOfReception(
    PduIdType udtDcmRxPduId)
#endif
{
  uint8             u8RxProtocolIndex;
  uint8             u8RxProtocolPriority;
  uint8             u8RxBufferId;
  BufReq_ReturnType enuReturn;

  u8RxProtocolIndex = u8RX_PROTOCOL_IDX(udtDcmRxPduId);
  u8RxBufferId = u8RX_BUFFER_ID(u8RxProtocolIndex);
  u8RxProtocolPriority = u8PROT_PRIORITY(u8RxProtocolIndex);

  /*! If the new RxPduId is the same as the current main protocol
   *  RxPduId */
  if(udtDcmRxPduId == Dsl_udtMainProtRxPduId)
  {
    /* Dcm557, Dcm241 */
    /*! Set the return value to BUFREQ_E_NOT_OK */
    enuReturn = BUFREQ_E_NOT_OK;
  }
  /*! Else if the new protocol is the same as the current one */
  else if(u8RxProtocolIndex == Dsl_u8MainProtocolIndex)
  {
    /*! Set the return value to BUFREQ_E_NOT_OK */
    enuReturn = BUFREQ_E_NOT_OK;
  }
  /*! Else if the new protocol RX buffer is locked */
  else if(Dsl_astrBufferInfo[u8RxBufferId].udtStatus == u8ST_BUFF_LOCKED)
  {
    /*! Set the return value to BUFREQ_E_BUSY */
    /* Dcm445, Dcm241 */
    enuReturn = BUFREQ_E_BUSY;
  }
  /*! Else if new protocol priority is lower than the current one */
  /*! Here we have two PduIds of two different protocols not share
     the buffer */ /* Dcm015 */
  else if(u8RxProtocolPriority >=
          u8PROT_PRIORITY(Dsl_u8MainProtocolIndex))
  {
    /* Dcm656 & Dcm655 */
    /*! Set the return value to BUFREQ_E_NOT_OK */
    enuReturn = BUFREQ_E_NOT_OK;
  }
  /*! Else, Preemption */
  else
  {
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
    /*! IF DCM_udtPROT_PREEMPT_SESSION equals DCM_ALL_SESSION_LEVEL */
    #if(DCM_udtPROT_PREEMPT_SESSION == u8ALL_SESSION_LEVEL)
    /*! Set the preempt flag */
    *pbProtocolPreempt = TRUE;
    /*! Set the return value to BUFREQ_OK */
    enuReturn = BUFREQ_OK;
    /*! ELSE */
    #else
    /*! If the current session equals DCM_udtPROT_PREEMPT_SESSION */
    if(Dcm_u8eCurrSesCtrl == DCM_udtPROT_PREEMPT_SESSION)
    {
      /*! Set the preempt flag */
      *pbProtocolPreempt = TRUE;
      /*! Set the return value to BUFREQ_OK */
      enuReturn = BUFREQ_OK;
    }
    /*! Else */
    else
    {
      /*! Set the return value to BUFREQ_E_NOT_OK */
      enuReturn = BUFREQ_E_NOT_OK;
    }
    #endif
#else
    /*! Set the return value to BUFREQ_E_NOT_OK */
    enuReturn = BUFREQ_E_NOT_OK;
#endif
  }

  return enuReturn;
}
/******************************************************************************/
/*! \Description Copies Main protocol response from main protocol TX buffer
    \return BUFREQ_OK: Copy is done successfully
            BUFREQ_E_NOT_OK: Copy fails
 *  \param[in] DcmRxPduId RxPduId of the indication protocol  \n
 *  \Range     0..65535 \n
 *  \param[in] MainProtRxPduId RxPduId of the current main protocol \n
 *  \Range     0..65535 \n
 *  \param[in] Result Result of the indication \n
 *  \Range     Range of NotifResultType \n
*******************************************************************************/
/* !Deviation : Inhibit MISRA rule [4700]: Metric STSUB threshold is violated
 *              for a better readability  */
/* PRQA S 4700 L1 */
static FUNC(void, DCM_CODE) vidMainRxIndication(
    PduIdType udtDcmRxPduId,
    PduIdType udtMainProtRxPduId,
    NotifResultType udtResult)
{
  Std_ReturnType udtReturn;

  /*! If the main protocol status is COPYING_RX_DATA */
  if(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_COPYING_RX_DATA)
  {
    /*! If Result is NTFRSLT_OK */
    if(udtResult == NTFRSLT_OK)
    {
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
      /*! If the preempting protocol status is not IDLE */
      if(Dsl_u8PreemptProtStatus != u8ST_PREEMPT_PROT_IDLE)
      {
        /*! End main process */
        vidEndOfMainMsgExec();
      }
      /*! Else if Dsl_bMainProtStarted is False */
      else
#endif
      if(Dsl_bMainProtStarted == FALSE)
      {
        /* Dcm036 */
        /*! Call u8StartProtocol() */
        udtReturn = u8StartProtocol(Dsl_u8MainProtocolIndex);
        /*! If u8StartProtocol() returns OK */
        if(udtReturn == E_OK)
        {
          /*! Set Dsl_bMainProtStarted */
          Dsl_bMainProtStarted = TRUE;
          /* Dcm147 */
          /*! Call BswM_Dcm_RequestSessionMode() for default session */
          BswM_Dcm_RequestSessionMode(DCM_DEFAULT_SESSION);
          /* Dcm144 */
          /*! Reload session timers */
          vidReloadSessionTimers(Dsl_u8MainProtocolIndex,
                                 DCM_DEFAULT_SESSION);
          /* Dcm147 */
          /*! Reset Dcm_u8eCurrSesCtrl to default */
          Dcm_u8eCurrSesCtrl  = DCM_DEFAULT_SESSION;
          /* Dcm146 */
          /*! Reset Dcm_u8eCurrSecLevel to LOCKED */
          Dcm_u8eCurrSecLevel = DCM_SEC_LEV_LOCKED;
          /* Dcm112 */
          /*! If the message is tester present with suppressed response
           *  and the addressing type is functional */
          if((bMSG_TP_AND_RESP_SUPP(u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex))
              == TRUE)
           &&(u8RX_ADDR_TYPE(udtDcmRxPduId) == DCM_FUNC_ADDR))
          {
            /* Dcm113, Dcm141, Dcm166 */
            /*! End main process */
            vidEndOfMainMsgExec();
          }
          /*! Else */
          else
          {
            /* Dcm163 */
            /*! Call ComM_DCM_ActiveDiagnostic() */
            ComM_DCM_ActiveDiagnostic(u8NETWORK_ID(udtMainProtRxPduId));
            /*! Set Dcm_beDiagnosticsActive */
            Dcm_beDiagnosticsActive = TRUE;
            /*! Prepare main message context */
            vidPrepMnProtMsgContext();
            /*! Set main protocol to PROCESSING */
            Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PROCESSING;
            /* Dcm111, Dcm035, Dcm145 */ /* Dcm195 */
            /*! Call DsdInternal_DataIndication() */
            DsdInternal_DataIndication(&Dsl_strMainProtMsgContext,
                                      u8SID_TABLE(Dsl_u8MainProtocolIndex));
          }
        }
        /*! Else If not all Xxx_StartProtocol() functions return OK */
        else
        {
          /*! Send NRC CNC */
          vidSendNrcCondNotCorr(Dsl_u8MainProtocolIndex,
                                udtMainProtRxPduId);
        }
      }
      /*! SUB-SEQUENT RX INDICATIONS */
      else
      {
        /*! As a new request shall be processed, DCM needs to guarantee
          timing to tester by sending busy responses. So P2Server Timer is
          started here. */
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase              */
        /* PRQA S 3141 ++                                                 */
        /* PRQA S 3138 ++                                                 */
        SchM_Enter_Dcm_Access_051();
        /* PRQA S 3138 --                                                 */
        /* PRQA S 3141 --                                                 */

        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase              */
        /* PRQA S 3141 ++                                                 */
        /* PRQA S 3138 ++                                                 */
        SchM_Enter_Dcm_Access_054();
        /* PRQA S 3138 --                                                 */
        /* PRQA S 3141 --                                                 */
        Dsl_u16P2Counter = Dsl_u16P2Reload;
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase              */
        /* PRQA S 3141 ++                                                 */
        /* PRQA S 3138 ++                                                 */
        SchM_Exit_Dcm_Access_054();
        /* PRQA S 3138 --                                                 */
        /* PRQA S 3141 --                                                 */

        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase              */
        /* PRQA S 3141 ++                                                 */
        /* PRQA S 3138 ++                                                 */
        SchM_Exit_Dcm_Access_051();
        /* PRQA S 3138 --                                                 */
        /* PRQA S 3141 --                                                 */

        /* Dcm112 */
        /*! If message is tester present with suppressed response and
         *  addressing type is functional */
        if((bMSG_TP_AND_RESP_SUPP(u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex))
            == TRUE)
         &&(u8RX_ADDR_TYPE(udtDcmRxPduId) == DCM_FUNC_ADDR))
        {
          /* Dcm113, Dcm141, Dcm166 */
          /*! End main protocol process */
          vidEndOfMainMsgExec();
        }
        /*! Else */
        else
        {
          /*! If the current session is the default */
          if(Dcm_u8eCurrSesCtrl == DCM_DEFAULT_SESSION)
          {
            /* Dcm163 */
            /*! Call ComM_DCM_ActiveDiagnostic() */
            ComM_DCM_ActiveDiagnostic(u8NETWORK_ID(udtMainProtRxPduId));
            /*! Set Dcm_beDiagnosticsActive */
            Dcm_beDiagnosticsActive = TRUE;
          }
          /*! Else the current session is non-default */ /* Dcm169 */
          else
          {
            /* Dcm141 */
            /*! Do nothing */
          }
          /*! Prepare main protocol message context */
          vidPrepMnProtMsgContext();
          /*! Set main protocol status to PROCESSING */
          Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PROCESSING;
          /* Dcm111, Dcm035 */ /* Dcm195 */
          /*! Call DsdInternal_DataIndication() */
          DsdInternal_DataIndication(&Dsl_strMainProtMsgContext,
                                     u8SID_TABLE(Dsl_u8MainProtocolIndex));
        }
      }
    }
    /*! Else if not NTFRSLT_OK */ /* Dcm344 */
    else
    {
      /*! End main message process */
      vidEndOfMainMsgExec();
    }
  }
  /*! Else if the main protocol status is WAIT_CANCEL_RX */
  else if(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_WAIT_CANCEL_RX)
  {
    /*! Case of RxInd of CancelReceive Request */
    /* Dcm577 */
    /*! Whatever the "Result" value is, terminate the main protocol
     * execution. */
    vidEndOfMainMsgExec();
  }
  /*! Else if other main status */
  else
  {
    /*! Do nothing. */
  }
}
/* PRQA L:L1 */
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Starts the protocol for the first time
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidStartProtocol(
    PduIdType udtDcmRxPduId,
    PduIdType udtMainProtRxPduId)
{
  Std_ReturnType udtReturn;

  /* Dcm036 */
  /*! Call u8StartProtocol for the preempting protocol */
  udtReturn = u8StartProtocol(Dsl_u8PreemptProtocolIndex);
  /*! If u8StartProtocol() returns E_OK */
  if(udtReturn == E_OK)
  {
    /*! Set Dsl_bMainProtStarted */
    Dsl_bMainProtStarted = TRUE;
    /*! Set Dsl_u8MainProtocolIndex with Dsl_u8PreemptProtocolIndex */
    Dsl_u8MainProtocolIndex = Dsl_u8PreemptProtocolIndex;
    Dcm_u8eMainProtocolID = u8PROTOCOL_ID(Dsl_u8MainProtocolIndex);
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PROCESSING;

    Dsl_udtMainProtRxPduId = Dsl_udtPreemptRxPduId;
    udtMainProtRxPduId     = Dsl_udtMainProtRxPduId;

    /*! Set Dsl_u8PreemptProtStatus to u8ST_PREEMPT_PROT_IDLE */
    Dsl_u8PreemptProtStatus = u8ST_PREEMPT_PROT_IDLE;

    /* Dcm147 */
    /*! Call BswM_Dcm_RequestSessionMode() with default session */
    BswM_Dcm_RequestSessionMode(DCM_DEFAULT_SESSION);
    /* Dcm144 */
    vidReloadSessionTimers(Dsl_u8MainProtocolIndex,DCM_DEFAULT_SESSION);
    /* Dcm147 */
    /*! Set current session to default */
    Dcm_u8eCurrSesCtrl  = DCM_DEFAULT_SESSION;
    /* Dcm146 */
    /*! Set current security level to locked */
    Dcm_u8eCurrSecLevel = DCM_SEC_LEV_LOCKED;
    /* Dcm112 */
    /*! If received message is tester present with suppressed response
     *  and addressing type is functional */
    if((bMSG_TP_AND_RESP_SUPP(u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex))
        == TRUE)
     &&(u8RX_ADDR_TYPE(udtDcmRxPduId) == DCM_FUNC_ADDR))
    {
      /* Dcm113, Dcm141, Dcm166 */
      /*! End the main protocol execution */
      vidEndOfMainMsgExec();
    }
    /*! Else */
    else
    {
      /* Dcm163 */
      /*! Call ComM_DCM_ActiveDiagnostic() to activate the diagnostics
       *  for the new protocol */
      ComM_DCM_ActiveDiagnostic(u8NETWORK_ID(udtMainProtRxPduId));
      /*! Set Dcm_beDiagnosticsActive */
      Dcm_beDiagnosticsActive = TRUE;
      vidPrepMnProtMsgContext();
      /*! Set main protocol status to u8ST_MN_PROT_PROCESSING */
      Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PROCESSING;
      /* Dcm111, Dcm035, Dcm145 */ /* Dcm195 */
      /*! Call DsdInternal_DataIndication() */
      DsdInternal_DataIndication(&Dsl_strMainProtMsgContext,
                                 u8SID_TABLE(Dsl_u8MainProtocolIndex));
    }
  }
  /*! Else If NOT all Xxx_StartProtocol() functions return OK */
  else
  {
    /*! Call vidSendNrcCondNotCorr() to send a CNC NRC */
    vidSendNrcCondNotCorr(Dsl_u8MainProtocolIndex,
                          udtMainProtRxPduId);
  }
}
/******************************************************************************/
/*! \Description Executes the protocol switching process
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSwitchProtocol(
    PduIdType udtDcmRxPduId,
    PduIdType udtMainProtRxPduId)
{
  Std_ReturnType udtReturn;

  /*! Switch Protocol */
  /*! Call u8StartProtocol() */
  udtReturn = u8StartProtocol(Dsl_u8PreemptProtocolIndex);
  /*! If u8StartProtocol() returns E_OK */
  if(udtReturn == E_OK)
  {
    /*! Finally, preemption is executed without problems. */
    if(Dcm_u8eCurrSesCtrl != DCM_DEFAULT_SESSION)
    {
      /* Dcm168 */
      /*! Call ComM_DCM_InactiveDiagnostic() */
      ComM_DCM_InactiveDiagnostic(
                          u8NETWORK_ID(udtMainProtRxPduId));
      /*! Clear Dcm_beDiagnosticsActive */
      Dcm_beDiagnosticsActive = FALSE;
    }
    /*! Reload session timers */
    vidReloadSessionTimers(
               Dsl_u8PreemptProtocolIndex, DCM_DEFAULT_SESSION);
    /*! Call ComM_DCM_ActiveDiagnostic() */
    ComM_DCM_ActiveDiagnostic(
                           u8NETWORK_ID(Dsl_udtPreemptRxPduId));
    /*! Set Dcm_beDiagnosticsActive */
    Dcm_beDiagnosticsActive = TRUE;
    /*! Set current session to default */
    Dcm_u8eCurrSecLevel = DCM_SEC_LEV_LOCKED;
    /*! Set the current security level to LOCKED */
    Dcm_u8eCurrSesCtrl = DCM_DEFAULT_SESSION;
    /*! Set the main protocol index to the preempting protocol
     *  index */
    Dsl_u8MainProtocolIndex = Dsl_u8PreemptProtocolIndex;
    /*! Set Dcm_u8eMainProtocolID with the new protocol ID */
    Dcm_u8eMainProtocolID = u8PROTOCOL_ID(Dsl_u8MainProtocolIndex);
    /*! Set the main protocol status to PROCESSING */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PROCESSING;
    /*! Set the main protocol RxPduId with that of the
     *  preempting protocol */
    Dsl_udtMainProtRxPduId = Dsl_udtPreemptRxPduId;
    /*! Set Dsl_u8PreemptProtStatus to IDLE */
    Dsl_u8PreemptProtStatus = u8ST_PREEMPT_PROT_IDLE;

    /*! Call DspInternal_vidProtPreemptNotify() */
    DspInternal_vidProtPreemptNotify();

    /* Dcm112 */
    /*! If tester present with suppressed response and
     *  functional addressing */
    if((bMSG_TP_AND_RESP_SUPP(u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex))
        == TRUE)
     &&(u8RX_ADDR_TYPE(udtDcmRxPduId) == DCM_FUNC_ADDR))
    {
      /*! End main protocol execution */
      vidEndOfMainMsgExec(); /* Dcm113, Dcm141, Dcm166 */
    }
    /*! Else */
    else
    {
      /*! Call vidPrepMnProtMsgContext() */
      vidPrepMnProtMsgContext();
      /* Dcm111, Dcm035, Dcm195 */
      /*! Call DsdInternal_DataIndication() */
      DsdInternal_DataIndication(&Dsl_strMainProtMsgContext,
                          u8SID_TABLE(Dsl_u8MainProtocolIndex));
    }
  }
  /*! Else */
  else
  {
    /*! Send CNC NRC */
    vidSendNrcCondNotCorr(Dsl_u8PreemptProtocolIndex,
                          Dsl_udtPreemptRxPduId);
  }
}
#endif
/******************************************************************************/
/*! \Description Executes the processing done procedure for the main protocol
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidMainProcessingDone(PduIdType udtMainProtRxPduId)
{
  uint8           u8TxBufferId;
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;

  /*! If Main state is processing */
  if(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_PROCESSING)
  {
    /*! If cancel bit is high */
    if(Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation == TRUE)
    {
      /*! If no internal Tx is in progress */
      if((Dsl_bIntTxInProgress == FALSE)
       &&(Dsl_bFrcdRCRRPInProgress == FALSE))
      {
        /*! If no General Reject is pending */
        if(Dsl_bGeneralRejectPend == FALSE)
        {
          /*! End main msg process */
          vidEndOfMainMsgExec();
        }
        /*! Else */
        else
        {
          /*! Clear General Reject Pend flag */
          Dsl_bGeneralRejectPend = FALSE;
          /*! Call vidSendGeneralReject() */
          vidSendGeneralReject();
        }
      }
      else
      {
        /*! If no General Reject is pending */
        if(Dsl_bGeneralRejectPend == TRUE)
        {
          /*! Set the main protocol status to GR_TX_PENDING */
          Dsl_u8MainProtocolStatus = u8ST_MN_PROT_GR_TX_PENDING;
        }
        /*! Else if no General Reject pending */
        else
        {
          /*! Set main status to WAIT_TO_END_PRCS */
          Dsl_u8MainProtocolStatus = u8ST_MN_PROT_WAIT_TO_END_PRCS;
        }
      }
    }
    /*! Else */
    else
    {
      /*! If no Internal Tx or forced RCRRP is in progress */
      if((Dsl_bIntTxInProgress == FALSE)
       &&(Dsl_bFrcdRCRRPInProgress == FALSE))
      {
        /*! If response is to be suppressed */
        if(Dsl_strMainProtMsgContext.resDataLen ==
            DspInternal_udtSUPPRESS_RESP_LENGTH)
        {
          /*! End the main process */
          /* Dcm166 */
          vidEndOfMainMsgExec();
        }
        /*! Else */
        else
        {
          u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
          udtPduInfo.SduLength  =
              (PduLengthType)Dsl_strMainProtMsgContext.resDataLen;

          udtPduInfo.SduDataPtr =
              Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;

          /* Dcm115 */ /* Dcm237 */
          Dsl_u8MainProtocolStatus = u8ST_MN_PROT_TX_IN_PROGRESS;
          /*! Transmit the response */
          udtPdurTransmitReturn =
              PduR_DcmTransmit(udtTX_PDU_REF(udtMainProtRxPduId),
                               &udtPduInfo);
          /*! If PduR_DcmTransmit() returns not OK */
          if(udtPdurTransmitReturn != E_OK)
          {
            /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
            DsdInternal_Confirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                                     udtMainProtRxPduId,
                                     NTFRSLT_E_NOT_OK);
            /*! End main context execution */
            vidEndOfMainMsgExec();
          }
        }
      }
      /*! Else if there is an internal TX in progress */
      else
      {
        /*! Set the main protocol status to TX_PENDING */
        Dsl_u8MainProtocolStatus = u8ST_MN_PROT_TX_PENDING;
      }
    }
  }
}
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Executes the processing done procedure for the main protocol
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidMainProcessPage(Dcm_MsgLenType udtFilledPageLen)
{
  uint8           u8TxBufferId;
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;

  if(Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation == TRUE)
  {
    /*! If no internal Tx is in progress */
    if((Dsl_bIntTxInProgress == FALSE)
     &&(Dsl_bFrcdRCRRPInProgress == FALSE))
    {
      /*! If no General Reject is pending */
      if(Dsl_bGeneralRejectPend == FALSE)
      {
        /*! End main msg process */
        vidEndOfMainMsgExec();
      }
      /*! Else */
      else
      {
        /*! Clear General Reject Pend flag */
        Dsl_bGeneralRejectPend = FALSE;
        /*! Call vidSendGeneralReject() */
        vidSendGeneralReject();
      }
    }
    else
    {
      /*! If no General Reject is pending */
      if(Dsl_bGeneralRejectPend == TRUE)
      {
        /*! Set the main protocol status to GR_TX_PENDING */
        Dsl_u8MainProtocolStatus = u8ST_MN_PROT_GR_TX_PENDING;
      }
      /*! Else if no General Reject pending */
      else
      {
        /*! Set main status to WAIT_CANCEL_TX */
        Dsl_u8MainProtocolStatus = u8ST_MN_PROT_WAIT_CANCEL_INT_TX;
        /*! Cancel Internal Tx */
        udtPdurTransmitReturn =
         PduR_DcmCancelTransmitRequest(udtTX_PDU_REF(Dsl_udtMainProtRxPduId));
        /*! If Cancellation failed */
        if(udtPdurTransmitReturn != E_OK)
        {
          /*! End the main message context */
          vidEndOfMainMsgExec();
        }
      }
    }
  }
  /*! If the main protocol status is PROCESSING (first page) */
  else if(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_PROCESSING)
  {
    /*! Reset the total copied response data length to 0 */
    Dsl_udtMnTotalPageCopiedLen = (Dcm_MsgLenType)0;
    /*! Reset the main page residue index to 0 */
    Dsl_udtMnPageResidueBuffIdx = (Dcm_MsgLenType)0;
    /*! If there is no internal TX in progress */
    if((Dsl_bIntTxInProgress == FALSE)
     &&(Dsl_bFrcdRCRRPInProgress == FALSE))
    {
      /*! Get the TX buffer Id of the main protocol */
      u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
      /*! Set the SduLength with the resDataLen of the main context */
      udtPduInfo.SduLength  =
                          (PduLengthType)Dsl_strMainProtMsgContext.resDataLen;
      /*! Set the SduDataPtr to the main protocol TX buffer pointer */
      udtPduInfo.SduDataPtr =
                 Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;
      /* Dcm237 */
      /*! Set the Dsl_udtFilledPageLen with FilledPageLen */
      Dsl_udtMainFilledPageLen = udtFilledPageLen;
      /*! Set the main protocol status to PAGE_DATA_PROCESSED */
      Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PAGE_DATA_PROCESSED;

      /*! Call PduR_DcmTransmit() to initiate the transmission of the first
       *  page. */
      udtPdurTransmitReturn =
          PduR_DcmTransmit(udtTX_PDU_REF(Dsl_udtMainProtRxPduId),
                           &udtPduInfo);

      /*! If PduR_DcmTransmit() returns not OK */
      if(udtPdurTransmitReturn != E_OK)
      {
        /*! Call DsdInternal_Confirmation() with result NTFRSLT_E_NOT_OK */
        DsdInternal_Confirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                                 Dsl_udtMainProtRxPduId,
                                 NTFRSLT_E_NOT_OK);
        /*! Call vidEndOfMainMsgExec() to end the main protocol message
         *  execution */
        vidEndOfMainMsgExec();
      }
    }
    /*! Else if there is an internal TX in progress */
    else
    {
      /*! Set the main status to PAGE_TX_PENDING to be resumed when the
       *  internal TX is finished */
      Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PAGE_TX_PENDING;
      /*! Set Dsl_udtFilledPageLen with FilledPageLen */
      Dsl_udtMainFilledPageLen = udtFilledPageLen;
    }
  }
  /*! Else if main protocol status is PAGE_UPDATE_REQUESTED (not first page)*/
  else if(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_PAGE_UPDATE_REQUESTED)
  {
    /*! Reload P2 timer */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
    /*              implemented during integration phase              */
    /* PRQA S 3141 ++                                                 */
    /* PRQA S 3138 ++                                                 */
    SchM_Enter_Dcm_Access_051();
    /* PRQA S 3138 --                                                 */
    /* PRQA S 3141 --                                                 */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
    /*              implemented during integration phase              */
    /* PRQA S 3141 ++                                                 */
    /* PRQA S 3138 ++                                                 */
    SchM_Enter_Dcm_Access_054();
    /* PRQA S 3138 --                                                 */
    /* PRQA S 3141 --                                                 */
    Dsl_u16P2Counter = Dsl_u16P2Reload;
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
    /*              implemented during integration phase              */
    /* PRQA S 3141 ++                                                 */
    /* PRQA S 3138 ++                                                 */
    SchM_Exit_Dcm_Access_054();
    /* PRQA S 3138 --                                                 */
    /* PRQA S 3141 --                                                 */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
    /*              implemented during integration phase              */
    /* PRQA S 3141 ++                                                 */
    /* PRQA S 3138 ++                                                 */
    SchM_Exit_Dcm_Access_051();
    /* PRQA S 3138 --                                                 */
    /* PRQA S 3141 --                                                 */
    /*! Set Dsl_udtFilledPageLen with FilledPageLen */
    Dsl_udtMainFilledPageLen = udtFilledPageLen;
    /*! Set the main status to PAGE_DATA_PROCESSED */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PAGE_DATA_PROCESSED;
  }
  /*! Else */
  else
  {
    /* Do nothing. */
  }
}
#endif
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Executes the processing done procedure for the Periodic
 *               protocol
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidPeriodicProcessingDone(
    Dcm_IdContextType udtIdContext)
{
  uint8           u8ConnRef;
  uint8           u8PeriodicProtIdx;
  uint8           u8NumPeriodicTx;
  uint8           u8TransType;
  uint8           u8TxBufferId;
  PduIdType       udtTxPduRef;
  uint32          u32TxBufferQuota;
  PduInfoType     udtPduInfo;
  PduIdType       udtTxConfPduId;
  PduR_ReturnType udtPdurTransmitReturn;
  uint8           u8PeriodicProtArrIdx;
  P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR)
                  pstrPeriodicMsgContext;


#if(DCM_bROE_ENABLED == STD_ON)
  u8PeriodicProtArrIdx = (Dcm_IdContextType)(udtIdContext - 2);
#else
  u8PeriodicProtArrIdx = (Dcm_IdContextType)(udtIdContext - 1);
#endif

  pstrPeriodicMsgContext =
      &Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtMsgContext;

  /*! Get the connection reference of the main protocol RxPduId */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);

  /*! If the periodic transmission container exists (not null) */
  if(pkstrPERIODIC_TRANS_PTR(Dsl_u8MainProtocolIndex,u8ConnRef)
      != (Dcm_DslPeriodicTransmissionType*)NULL_PTR)
  {
    /*! Get the periodic protocol index */
    u8PeriodicProtIdx =
        u8PERIODIC_PROT_IDX(Dsl_u8MainProtocolIndex, u8ConnRef);
    /*! Get the number of periodic TX channels */
    u8NumPeriodicTx = u8PERIODIC_NUM_TX(Dsl_u8MainProtocolIndex, u8ConnRef);

    /*! If the idContext is less or equal to the number of periodic TX
     *  channels */
    if(udtIdContext <= u8NumPeriodicTx)
    {
      /*! If the periodic protocol status is PROCESSING */
      if(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus ==
          u8ST_PERIODIC_PROT_PROCESSING)
      {
        /*! Get the periodic protocol TransType */
        u8TransType = u8PROT_TRANS_TYPE(u8PeriodicProtIdx);

        if(u8TransType == DCM_PROTOCOL_TYPE1)
        {
          /*! Get the periodic protocol TX buffer Id */
          u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
          /*! Get the TxPduRef of the main protocol */
          udtTxPduRef  = udtTX_PDU_REF(Dsl_udtMainProtRxPduId);
        }
        else
        {
          /*! Get the periodic protocol TX buffer Id */
          u8TxBufferId = u8TX_BUFFER_ID(u8PeriodicProtIdx);
          /*! Get the TxConfPduId */
          udtTxConfPduId = Dcm_pkstrePbConfig->strPbDcmDslConfig.
              pkstrDcmDslProtocolRow[Dsl_u8MainProtocolIndex].
              ppkstrDcmDslConnection[u8ConnRef]->
              pkstrDcmDslPeriodicTransmission->
              pudtDcmDslTxConfirmPduIds[u8PeriodicProtArrIdx];
          /*! Get the TxPduRef */
          udtTxPduRef = Dcm_pkstrePbConfig->strPbDcmDslConfig.
              pkstrDcmDslProtocolTx[udtTxConfPduId].
              udtDcmDslProtocolTxPduRef;
        }

        /*! If the periodic protocol cancel bit is raised */
        if((pstrPeriodicMsgContext->msgAddInfo.
            cancelOperation == TRUE)
         ||(Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[0] ==
             DspInternal_u8SID_NEG_RESP)
         ||(pstrPeriodicMsgContext->resDataLen
             == DspInternal_udtSUPPRESS_RESP_LENGTH))
        {
          /*! Call vidEndOfPeriodicMsgExec() */
          vidEndOfPeriodicMsgExec(u8PeriodicProtArrIdx);
        }
        /*! Else if the cancel bit is not raised */
        else
        {
          /*! If the periodic protocol TransType is TYPE1 */
          if(u8TransType == DCM_PROTOCOL_TYPE1)
          {
            /*! Set the SduLength */
            udtPduInfo.SduLength  =
                (PduLengthType)pstrPeriodicMsgContext->resDataLen;
            /*! Set the SduDataPtr */
            udtPduInfo.SduDataPtr =
                &Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].
                pudtBuffer[0];
          }
          /*! Else if the periodic protocol TransType is TYPE2 */
          else
          {
            /*! Get the periodic protocol TX buffer quota as the total size of
             *  the periodic protocol buffer divided by
             *  DCM_u8MAX_NUM_PERIODIC_TX */
            u32TxBufferQuota = Dcm_kstreDslConfig.
                astrDcmDslBuffer[u8TxBufferId].
                udtBufferSize/DCM_u8MAX_NUM_PERIODIC_TX;

            /*! Set the SduLength */
            udtPduInfo.SduLength = (PduLengthType)
                                   (pstrPeriodicMsgContext->resDataLen - 1);
            /*! Set the SduDataPtr */
            udtPduInfo.SduDataPtr =
                &Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].
                pudtBuffer[(u32TxBufferQuota*u8PeriodicProtArrIdx)+1];
          }

          /* Dcm237 */
          /*! Set the periodic protocol status to TX_IN_PROGRESS */
          Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus =
              u8ST_PERIODIC_PROT_TX_IN_PROGRESS;
          /*! Set the periodic protocol TxPduRef */
          Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtPeriodicTxPduRef =
              udtTxPduRef;
          /*! Call PduR_DcmTransmit() to send the response */
          udtPdurTransmitReturn = PduR_DcmTransmit(udtTxPduRef, &udtPduInfo);
          /*! If PduR_DcmTransmit() returns not E_OK */
          if(udtPdurTransmitReturn != E_OK)
          {
            /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
            DsdInternal_Confirmation(udtIdContext,
                                     pstrPeriodicMsgContext->dcmRxPduId,
                                     NTFRSLT_E_NOT_OK);
            /*! Call vidEndOfPeriodicMsgExec() */
            vidEndOfPeriodicMsgExec(u8PeriodicProtArrIdx);
          }
        }
      }
    }
  }
}
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Executes the processing done procedure for the Roe
 *               protocol
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidPeriodicProcessPage(
    Dcm_IdContextType udtIdContext,
    Dcm_MsgLenType udtFilledPageLen)
{
  uint8           u8TxBufferId;
  uint8           u8TransType;
  PduInfoType     udtPduInfo;
  PduIdType       udtTxPduRef;
  PduIdType       udtTxConfPduId;
  uint8           u8ConnRef;
  uint8           u8PeriodicProtIdx;
  uint8           u8PeriodicProtArrIdx;
  uint32          u32TxBufferQuota;
  P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR)
                  pstrPeriodicMsgContext;

  #if(DCM_bROE_ENABLED == STD_ON)
  u8PeriodicProtArrIdx = (Dcm_IdContextType)(udtIdContext - 2);
  #else
  u8PeriodicProtArrIdx = (Dcm_IdContextType)(udtIdContext - 1);
  #endif

  pstrPeriodicMsgContext =
      &Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtMsgContext;

  u8PeriodicProtIdx =
      Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].u8PeriodicProtIndex;

  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);

  if(pstrPeriodicMsgContext->msgAddInfo.cancelOperation == TRUE)
  {
    /*! Call vidEndOfPeriodicMsgExec() */
    vidEndOfPeriodicMsgExec(u8PeriodicProtArrIdx);
  }
  /*! If the main protocol status is PROCESSING (first page) */
  else if(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus ==
      u8ST_PERIODIC_PROT_PROCESSING)
  {
    /*! Get the Periodic protocol TransType */
    u8TransType = u8PROT_TRANS_TYPE(u8PeriodicProtIdx);

    if(u8TransType == DCM_PROTOCOL_TYPE1)
    {
      /*! Get the periodic protocol TX buffer Id */
      u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
      /*! Get the TxPduRef of the main protocol */
      udtTxPduRef  = udtTX_PDU_REF(Dsl_udtMainProtRxPduId);
      /*! Set the SduLength */
      udtPduInfo.SduLength =
          (PduLengthType)pstrPeriodicMsgContext->resDataLen;
      /*! Set the SduDataPtr */
      udtPduInfo.SduDataPtr =
          &Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].
          pudtBuffer[0];
    }
    else
    {
      /*! Get the periodic protocol TX buffer Id */
      u8TxBufferId = u8TX_BUFFER_ID(u8PeriodicProtIdx);
      /*! Get the TxConfPduId */
      udtTxConfPduId = Dcm_pkstrePbConfig->strPbDcmDslConfig.
          pkstrDcmDslProtocolRow[Dsl_u8MainProtocolIndex].
          ppkstrDcmDslConnection[u8ConnRef]->
          pkstrDcmDslPeriodicTransmission->
          pudtDcmDslTxConfirmPduIds[u8PeriodicProtArrIdx];
      /*! Get the TxPduRef */
      udtTxPduRef = Dcm_pkstrePbConfig->strPbDcmDslConfig.
          pkstrDcmDslProtocolTx[udtTxConfPduId].
          udtDcmDslProtocolTxPduRef;

      /*! Get the periodic protocol TX buffer quota as the total size of
       *  the periodic protocol buffer divided by
       *  DCM_u8MAX_NUM_PERIODIC_TX */
      u32TxBufferQuota = Dcm_kstreDslConfig.
          astrDcmDslBuffer[u8TxBufferId].
          udtBufferSize/DCM_u8MAX_NUM_PERIODIC_TX;

      /*! Set the SduLength */
      udtPduInfo.SduLength =
          (PduLengthType)(pstrPeriodicMsgContext->resDataLen - 1);
      /*! Set the SduDataPtr */
      udtPduInfo.SduDataPtr =
          &Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].
          pudtBuffer[(u32TxBufferQuota*u8PeriodicProtArrIdx)+1];
    }

    /* Dcm237 */
    /*! Set the Dsl_udtPeriodicFilledPageLen with FilledPageLen */
    Dsl_audtPeriodFilledPageLen[u8PeriodicProtArrIdx] = udtFilledPageLen;
    /*! Set the main protocol status to u8ST_PERIODIC_PROT_PAGE_DATA_PROCESSED*/
    Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus =
        u8ST_PERIODIC_PROT_PAGE_DATA_PROCESSED;
    Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtPeriodicTxPduRef =
        udtTxPduRef;

    /*! Reset the total copied response data length to 0 */
    Dsl_audtPeriodTotalPageCopiedLen[u8PeriodicProtArrIdx] =
        (Dcm_MsgLenType)0;
    /*! Reset the page residue index to 0 */
    Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx] =
        (Dcm_MsgLenType)0;

    /* !Deviation : Inhibit MISRA rule [3416]: function call is used in
     *              conditional statement for better readability              */
    /* PRQA S 3416 ++                                                         */
    if(PduR_DcmTransmit(udtTxPduRef, &udtPduInfo) != E_OK)
    {
      /* PRQA S 3416 --                                                       */
      /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
      DsdInternal_Confirmation(udtIdContext,
                               pstrPeriodicMsgContext->dcmRxPduId,
                               NTFRSLT_E_NOT_OK);
      /*! Call vidEndOfPeriodicMsgExec() */
      vidEndOfPeriodicMsgExec(u8PeriodicProtArrIdx);
    }
  }
  /*! Else if main protocol status is PAGE_UPDATE_REQUESTED (not first page)*/
  else if(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus ==
      u8ST_PERIODIC_PROT_PAGE_UPDATE_REQUESTED)
  {
    /*! Set Dsl_udtPeriodicFilledPageLen with FilledPageLen */
    Dsl_audtPeriodFilledPageLen[u8PeriodicProtArrIdx] = udtFilledPageLen;
    /*! Set the periodic protocol status to PAGE_DATA_PROCESSED */
    Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus =
        u8ST_PERIODIC_PROT_PAGE_DATA_PROCESSED;
  }
  /*! Else */
  else
  {
    /* Do nothing. */
  }
}
#endif
#endif
#if(DCM_bROE_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Executes the processing done procedure for the Roe
 *               protocol
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidRoeProcessingDone(void)
{
  uint8           u8ConnRef;
  uint8           u8TransType;
  uint8           u8TxBufferId;
  PduIdType       udtTxPduRef;
  PduInfoType     udtPduInfo;
  PduIdType       udtTxConfPduId;

  /*! Get the connection reference of main Rx PduId */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);

  /*! If the periodic transmission container exists (not null) */
  if(pkstrROE_PTR(Dsl_u8MainProtocolIndex,u8ConnRef)
      != (Dcm_DslResponseOnEventType*)NULL_PTR)
  {
    /*! If the ROE protocol status is PROCESSING */
    if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_PROCESSING)
    {
      /*! Get the ROE protocol TransType */
      u8TransType = u8PROT_TRANS_TYPE(Dsl_strRoeProt.u8RoeProtIndex);

      /*! If Roe protocol TransType is TYPE1 */
      if(u8TransType == DCM_PROTOCOL_TYPE1)
      {
        /*! Get the TX Buffer ID of the main protocol */
        u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
        /*! Get the TX PduRef of the main protocol */
        udtTxPduRef  = udtTX_PDU_REF(Dsl_udtMainProtRxPduId);
      }
      /*! Else If Roe protocol TransType is TYPE2 */
      else
      {
        /*! Get the TX Buffer ID of the Roe protocol */
        u8TxBufferId = u8TX_BUFFER_ID(Dsl_strRoeProt.u8RoeProtIndex);
        /*! Get the TX Confirmation PduId of the Roe protocol */
        udtTxConfPduId = udtROE_TX_CONF_PDUID(Dsl_u8MainProtocolIndex,
                                              u8ConnRef);
        /*! Get the TX PduRef of the Roe protocol */
        udtTxPduRef = Dcm_pkstrePbConfig->strPbDcmDslConfig.
            pkstrDcmDslProtocolTx[udtTxConfPduId].udtDcmDslProtocolTxPduRef;
      }

      /*! If ROE protocol cancel bit is raised or the response is suppressed */
      if((Dsl_strRoeProt.udtMsgContext.msgAddInfo.cancelOperation == TRUE)
       ||(Dsl_strRoeProt.udtMsgContext.resDataLen == DspInternal_udtSUPPRESS_RESP_LENGTH)
       ||(Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[0] ==
           DspInternal_u8SID_NEG_RESP))
      {
        /*! Call vidEndOfRoeMsgExec() */
        vidEndOfRoeMsgExec();
      }
      /*! Else if the cancel bit is not raised */
      else
      {
        /*! Set the SduLength with the Dsl_strRoeProt resDataLen  */
        udtPduInfo.SduLength  = (PduLengthType)Dsl_strRoeProt.udtMsgContext.
            resDataLen;
        /*! Set the SduDataPtr with the TX Buffer Id  */
        udtPduInfo.SduDataPtr =
            Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;

        /*! Set the Roe protocol status to TX_IN_PROGRESS */
        Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_TX_IN_PROGRESS;
        /*! Set Dsl_strRoeProt.udtTxPduRef with the TxPduRef */
        Dsl_strRoeProt.udtRoeTxPduRef = udtTxPduRef;

        /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used
         *              in conditional statement for better readability       */
        /* PRQA S 3415 ++                                                     */
        /* PRQA S 3416 ++                                                     */

        /*! If Dsl_u16RoeInterMsgCounter has expired */
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be        */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Enter_Dcm_Access_057();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */
        if((Dsl_u16RoeInterMsgCounter == (uint16)0)
        && (PduR_DcmTransmit(udtTxPduRef, &udtPduInfo) == E_OK))
        {
          /* PRQA S 3415 --                                                   */
          /* PRQA S 3416 --                                                   */
          /*! Reload Dsl_u16RoeInterMsgCounter with
           *  DCM_u16DSP_ROE_INTER_MESSAGE_TIME */
          Dsl_u16RoeInterMsgCounter = DCM_u16DSP_ROE_INTER_MESSAGE_TIME;
          /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be      */
          /*              implemented during integration phase                */
          /* PRQA S 3141 ++                                                   */
          /* PRQA S 3138 ++                                                   */
          SchM_Exit_Dcm_Access_057();
          /* PRQA S 3138 --                                                   */
          /* PRQA S 3141 --                                                   */
        }
        /*! Else if Dsl_u16RoeInterMsgCounter has not expired yet */
        else
        {
          /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be      */
          /*              implemented during integration phase                */
          /* PRQA S 3141 ++                                                   */
          /* PRQA S 3138 ++                                                   */
          SchM_Exit_Dcm_Access_057();
          /* PRQA S 3138 --                                                   */
          /* PRQA S 3141 --                                                   */
          #if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
          /*! If Dsl_strRoeProt.bIsQueued is set */
          if(Dsl_strRoeProt.bIsQueued == TRUE)
          {
            /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
            /*              implemented during integration phase              */
            /* PRQA S 3141 ++                                                 */
            /* PRQA S 3138 ++                                                 */
            SchM_Enter_Dcm_Access_058();
            /* PRQA S 3138 --                                                 */
            /* PRQA S 3141 --                                                 */
            /*! If the Roe Transmission Queue is free */
            if(Dsl_bRoeTransQueStatus == u8ST_BUFF_FREE)
            {
              /*! Lock the Roe Transmission Queue */
              Dsl_bRoeTransQueStatus = u8ST_BUFF_LOCKED;
              /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be  */
              /*              implemented during integration phase            */
              /* PRQA S 3141 ++                                               */
              /* PRQA S 3138 ++                                               */
              SchM_Exit_Dcm_Access_058();
              /* PRQA S 3138 --                                               */
              /* PRQA S 3141 --                                               */
              /*! Call vidQueueRoeResponse() to queue Roe Response */
              vidQueueRoeResponse(
                 (P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC))(&udtPduInfo));
              /*! Unlock the Roe Transmission Queue */
              Dsl_bRoeTransQueStatus = u8ST_BUFF_FREE;
            }
            /*! Else if the Roe Transmissions Queue is locked */
            else
            {
              /*! Set the Roe protocol status to PEND_QUE */
              Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_PEND_QUE;
            }
          }
          /*! Else if Queuing is not enabled for that event */
          else
          {
          #endif
            /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
            DsdInternal_Confirmation((Dcm_IdContextType)1,
                         Dsl_strRoeProt.udtMsgContext.dcmRxPduId,
                         NTFRSLT_E_NOT_OK);
          #if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
          }
          #endif
          /*! Call vidEndOfRoeMsgExec() */
          vidEndOfRoeMsgExec();
        }
      }
    }
  }
}
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Executes the processing done procedure for the Roe
 *               protocol
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidRoeProcessPage(Dcm_MsgLenType udtFilledPageLen)
{
  uint8           u8TxBufferId;
  uint8           u8TransType;
  PduInfoType     udtPduInfo;
  PduIdType       udtTxPduRef;
  PduIdType       udtTxConfPduId;
  uint8           u8ConnRef;

  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);
  /*! Get the ROE protocol TransType */
  u8TransType = u8PROT_TRANS_TYPE(Dsl_strRoeProt.u8RoeProtIndex);

  if(Dsl_strRoeProt.udtMsgContext.msgAddInfo.cancelOperation == TRUE)
  {
    /*! Call vidEndOfRoeMsgExec() */
    vidEndOfRoeMsgExec();
  }
  /*! If the main protocol status is PROCESSING (first page) */
  else if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_PROCESSING)
  {
    if(u8TransType == DCM_PROTOCOL_TYPE1)
    {
      u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
      udtTxPduRef  = udtTX_PDU_REF(Dsl_udtMainProtRxPduId);
    }
    else
    {
      u8TxBufferId = u8TX_BUFFER_ID(Dsl_strRoeProt.u8RoeProtIndex);
      udtTxConfPduId = udtROE_TX_CONF_PDUID(Dsl_u8MainProtocolIndex,
                                            u8ConnRef);
      /*! Get the TX PduRef of the Roe protocol */
      udtTxPduRef = Dcm_pkstrePbConfig->strPbDcmDslConfig.
          pkstrDcmDslProtocolTx[udtTxConfPduId].udtDcmDslProtocolTxPduRef;
    }

    /*! Set the SduLength with the resDataLen of the main context */
    udtPduInfo.SduLength  =
                        (PduLengthType)Dsl_strRoeProt.udtMsgContext.resDataLen;
    /*! Set the SduDataPtr to the main protocol TX buffer pointer */
    udtPduInfo.SduDataPtr =
               Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;
    /* Dcm237 */
    /*! Set the Dsl_udtFilledPageLen with FilledPageLen */
    Dsl_udtRoeFilledPageLen = udtFilledPageLen;
    /*! Set the main protocol status to u8ST_ROE_PROT_PAGE_DATA_PROCESSED */
    Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_PAGE_DATA_PROCESSED;
    Dsl_strRoeProt.udtRoeTxPduRef = udtTxPduRef;

    /*! Reset the total copied response data length to 0 */
    Dsl_udtRoeTotalPageCopiedLen = (Dcm_MsgLenType)0;
    /*! Reset the page residue index to 0 */
    Dsl_udtRoePageResidueBuffIdx = (Dcm_MsgLenType)0;

    /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used in
     *              conditional statement for better readability              */
    /* PRQA S 3415 ++                                                         */
    /* PRQA S 3416 ++                                                         */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be        */
    /*              implemented during integration phase                  */
    /* PRQA S 3141 ++                                                     */
    /* PRQA S 3138 ++                                                     */
    SchM_Enter_Dcm_Access_057();
    /* PRQA S 3138 --                                                     */
    /* PRQA S 3141 --                                                     */
    if((Dsl_u16RoeInterMsgCounter == (uint16)0)
    && (PduR_DcmTransmit(udtTxPduRef, &udtPduInfo) == E_OK))
    {
      /* PRQA S 3415 --                                                       */
      /* PRQA S 3416 --                                                       */
      /*! Reload Dsl_u16RoeInterMsgCounter with
       *  DCM_u16DSP_ROE_INTER_MESSAGE_TIME */
      Dsl_u16RoeInterMsgCounter = DCM_u16DSP_ROE_INTER_MESSAGE_TIME;
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be        */
      /*              implemented during integration phase                  */
      /* PRQA S 3141 ++                                                     */
      /* PRQA S 3138 ++                                                     */
      SchM_Exit_Dcm_Access_057();
      /* PRQA S 3138 --                                                     */
      /* PRQA S 3141 --                                                     */
    }
    /*! Else if Dsl_u16RoeInterMsgCounter has not expired yet */
    else
    {
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be        */
      /*              implemented during integration phase                  */
      /* PRQA S 3141 ++                                                     */
      /* PRQA S 3138 ++                                                     */
      SchM_Exit_Dcm_Access_057();
      /* PRQA S 3138 --                                                     */
      /* PRQA S 3141 --                                                     */
      /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
      DsdInternal_Confirmation((Dcm_IdContextType)1,
                   Dsl_strRoeProt.udtMsgContext.dcmRxPduId,
                   NTFRSLT_E_NOT_OK);
      /*! Call vidEndOfRoeMsgExec() */
      vidEndOfRoeMsgExec();
    }
  }
  /*! Else if main protocol status is PAGE_UPDATE_REQUESTED (not first page)*/
  else if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_PAGE_UPDATE_REQUESTED)
  {
    /*! Set Dsl_udtFilledPageLen with FilledPageLen */
    Dsl_udtRoeFilledPageLen = udtFilledPageLen;
    /*! Set the main status to PAGE_DATA_PROCESSED */
    Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_PAGE_DATA_PROCESSED;
  }
  /*! Else */
  else
  {
    /* Do nothing. */
  }
}
#endif
#endif
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Copies preempt protocol response from main protocol TX buffer
    \return BUFREQ_OK: Copy is done successfully
            BUFREQ_E_NOT_OK: Copy fails
 *  \param[in] DcmRxPduId RxPduId of the indication protocol  \n
 *  \Range     0..65535 \n
 *  \param[in] MainProtRxPduId RxPduId of the current main protocol \n
 *  \Range     0..65535 \n
 *  \param[in] Result Result of the indication \n
 *  \Range     Range of NotifResultType \n
*******************************************************************************/
static FUNC(void, DCM_CODE) vidPreemptRxIndication(
    PduIdType udtDcmRxPduId,
    PduIdType udtMainProtRxPduId,
    NotifResultType udtResult)
{
  /* If Result is OK => Preemption execution. */
  if(udtResult == NTFRSLT_OK)
  {
    /*! Dsl_bMainProtStarted is FALSE */
    if(Dsl_bMainProtStarted == FALSE)
    {
      /*! Call vidStartProtocol() */
      vidStartProtocol(udtDcmRxPduId, udtMainProtRxPduId);
    }
    /*! Else if all contexts are IDLE */
    /* !Deviation : Inhibit MISRA rule [3416]: function call is used in
     *              conditional statement for better readability              */
    /* PRQA S 3416 ++                                                         */
    else if(udtAllContextsIdle() == E_OK)
    {
      /* PRQA S 3416 --                                                       */
      /*! Call vidSwitchProtocol() */
      vidSwitchProtocol(udtDcmRxPduId, udtMainProtRxPduId);
    }
    /*! Else */
    else
    {
      /*! If there is no preemption timeout running */
      if(Dsl_bPreemptTimeoutOn == FALSE)
      {
        /*! Set Dsl_bPreemptTimeoutOn */
        Dsl_bPreemptTimeoutOn = TRUE;
        /*! Reload Dsl_u16PreemptTimeoutCtr with the configured
         *  value */
        Dsl_u16PreemptTimeoutCtr =
                       u16PREEMPT_TIMEOUT(Dsl_u8PreemptProtocolIndex);
      }
      /*! Send BusyRepeatRequest */
      vidSendNrcBusyRepeatReq();
    }
  }
  /*! Else if Result in not OK */ /* Dcm344 */
  else
  {
    vidEndOfPreemptMsgExec();
  }
}
/******************************************************************************/
/*! \Description Copies Main protocol response from main protocol TX buffer
    \return void
 *  \param[in] TxDataCntPtr Pointer to count of TX Data remaining in TX buffer\n
 *  \Range     Not Null \n
*******************************************************************************/
static FUNC(BufReq_ReturnType, DCM_CODE) udtPreemptCopyFromTxBuffer(
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr)
{
  uint8             u8TxBufferId;
  BufReq_ReturnType udtReturn = BUFREQ_OK;

  switch(Dsl_u8PreemptProtStatus)
  {
  /*! If preemting protocol status is TX_IN_PROGRESS or TX_CNC_IN_PROGRESS*/
  case u8ST_PREEMPT_PROT_TX_IN_PROGRESS:
  case u8ST_PREEMPT_PROT_TX_CNC_IN_PROGRESS:
    /*! Get preemting protocol TX buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8PreemptProtocolIndex);
    /*! Fill the first 3 bytes of PduInfoPtr->SduDataPtr with the first 3
     *  bytes of the TX buffer */
    PduInfoPtr->SduDataPtr[0] =
        Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[0];
    PduInfoPtr->SduDataPtr[1] =
        Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[1];
    PduInfoPtr->SduDataPtr[2] =
        Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[2];
    /*! Set value of TxDataCntPtr with 0 */
    *TxDataCntPtr = (PduLengthType)0;
    break;
  /*! Else */
  default:
    /*! Return BUFREQ_E_NOT_OK */
    udtReturn = BUFREQ_E_NOT_OK;
    break;
  }

  return udtReturn;
}
#endif
/******************************************************************************/
/*! \Description Copies Main protocol response from main protocol TX buffer
    \return BUFREQ_OK: Copy is done successfully
            BUFREQ_E_NOT_OK: Copy fails
 *  \param[in] DcmTxPduId TxPduRef of the main protocol  \n
 *  \Range     0..65535 \n
 *  \param[in] PduInfoPtr Pointer to the PduInfo \n
 *  \Range     Not Null \n
 *  \param[in] TxDataCntPtr Pointer to count of TX Data remaining in TX buffer\n
 *  \Range     Not Null \n
*******************************************************************************/
static FUNC(BufReq_ReturnType, DCM_CODE) udtMainCopyFromTxBuffer(
    PduIdType DcmTxPduId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr)
{
  uint8             u8ProtocolTxIdx;
  boolean           bTxPduIdFound = FALSE;
  uint8             u8ProtocolIdx;
  uint8             u8TxBufferId;
  Dcm_MsgLenType    udtRemainingDataLen;
  Dcm_MsgLenType    udtCopiedDataLen;
  PduLengthType     udtSduDataIdx;
  BufReq_ReturnType enuReturn = BUFREQ_OK;

  /*! Search for the TxPduRef in the configured protocol */
  for(u8ProtocolTxIdx = (uint8)0;
     (u8ProtocolTxIdx <
      Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslNumProtocolTx)
  && (bTxPduIdFound == FALSE);
     u8ProtocolTxIdx++)
  {
    /*! If found */
    if(Dcm_pkstrePbConfig->
        strPbDcmDslConfig.pkstrDcmDslProtocolTx[u8ProtocolTxIdx].
        udtDcmDslProtocolTxPduRef == DcmTxPduId)
    {
      bTxPduIdFound = TRUE;

      /*! Get the protocol index */
      u8ProtocolIdx = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                      pkstrDcmDslProtocolTx[u8ProtocolTxIdx].
                      u8DcmDslProtocolIndex;

      /*! Get the TX buffer Id */
      u8TxBufferId = u8TX_BUFFER_ID(u8ProtocolIdx);

      /*! If PduInfoPtr->SduLength is not 0 */
      if(PduInfoPtr->SduLength != (PduLengthType)0)
      {
        /*! Get data length remaining in the buffer */
        udtRemainingDataLen = Dsl_strMainProtMsgContext.resDataLen -
             Dsl_astrBufferInfo[u8TxBufferId].udtIndex;
        /*! If remaining data length is larger than 0 */
        if(udtRemainingDataLen > (Dcm_MsgLenType)0)
        {
          /* Dcm346 */
          /*! If the remaining data length is larger than or equals
           *  PduInfoPtr->SduLength */
          if(udtRemainingDataLen >= (Dcm_MsgLenType)PduInfoPtr->SduLength)
          {
            /*! Set copied data length to PduInfoPtr->SduLength */
            udtCopiedDataLen = (Dcm_MsgLenType)PduInfoPtr->SduLength;
          }
          /*! Else */
          else
          {
            /*! Set copied data length to the remaining data length */
            udtCopiedDataLen = udtRemainingDataLen;
          }

          /*! Copy the data from the TX buffer into PduInfoPtr->SduDataPtr */
          for(udtSduDataIdx = (PduLengthType)0;
              udtSduDataIdx < udtCopiedDataLen;
              udtSduDataIdx++)
          {
            PduInfoPtr->SduDataPtr[udtSduDataIdx] =
              Dcm_kstreDslConfig.
              astrDcmDslBuffer[u8TxBufferId].
              pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                         (Dcm_MsgLenType)udtSduDataIdx];
          }

          /*! Increase the TX buffer index by the length of the copied data */
          Dsl_astrBufferInfo[u8TxBufferId].udtIndex =
            Dsl_astrBufferInfo[u8TxBufferId].udtIndex + udtCopiedDataLen;
        }
        /*! Else if remaining data length is 0 */
        else
        {
          /*! Return BUFREQ_E_NOT_OK */
          enuReturn = BUFREQ_E_NOT_OK;
        }
      }

      /*! Set value of TxDataCntPtr with Dsl_strRoeProt.udtMsgContext.resDataLen
           *  minus the TX buffer index  */
      *TxDataCntPtr = (PduLengthType)
          (Dsl_strMainProtMsgContext.resDataLen -
          Dsl_astrBufferInfo[u8TxBufferId].udtIndex);
    }
  }

  /*! If the TxPduRef is not found */
  if(bTxPduIdFound == FALSE)
  {
    /*! Return BUFREQ_E_NOT_OK */
    enuReturn = BUFREQ_E_NOT_OK;
  }

  return enuReturn;
}
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Cancels the main protocol context
    \return      void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidCancelMainContext(void)
{
  Std_ReturnType udtReturn = E_OK;

  switch(Dsl_u8MainProtocolStatus)
  {
  /*! If main protocol status is COPYING_RX_DATA */
  case u8ST_MN_PROT_COPYING_RX_DATA:
    /* Dcm575 */ /*Dcm627*/
    /*! Set main protocol status to WAIT_CANCEL_RX */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_WAIT_CANCEL_RX;
    /*! Call PduR_DcmCancelReceiveRequest() */
    udtReturn = PduR_DcmCancelReceiveRequest(Dsl_udtMainProtRxPduId);
    break;
    /*! Else if main protocol status is TX_IN_PROGRESS or
     *  TX_GR_IN_PROGRESS */
  case u8ST_MN_PROT_TX_IN_PROGRESS:
  case u8ST_MN_PROT_TX_GR_IN_PROGRESS:
    /* Dcm079 */
    /*! Set main protocol status to WAIT_CANCEL_TX */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_WAIT_CANCEL_TX;
    /*! Call PduR_DcmCancelTransmitRequest() */
    udtReturn =
        PduR_DcmCancelTransmitRequest(udtTX_PDU_REF(Dsl_udtMainProtRxPduId));
    break;
    /*! Else if main protocol status is PROCESSING */
  case u8ST_MN_PROT_PROCESSING:
    /* Dcm559 */
    /*! Raise cancel bit of the main protocol context */
    Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation = TRUE;
    break;
    /*! Else if other main protocol status */
  default:
    /*! Reset the main status to IDLE */
    udtReturn = E_NOT_OK;
    break;
  }

  /*! If cancellation fails */
  if(udtReturn != E_OK)
  {
    /*! Reset the main protocol status to IDLE */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_IDLE;
  }
}
#endif
#if(DCM_bROE_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Cancels the Roe protocol context
    \return      void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidCancelRoeContext(void)
{
  Std_ReturnType udtReturn = E_OK;

  switch(Dsl_strRoeProt.udtProtStatus)
  {
  /*! If Roe protocol status is TX_IN_PROGRESS */
  case u8ST_ROE_PROT_TX_IN_PROGRESS:
    /*! Set the Roe protocol status to WAIT_CANCEL_TX */
    Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_WAIT_CANCEL_TX;
    /*! Call PduR_DcmCancelTransmitRequest() */
    udtReturn = PduR_DcmCancelTransmitRequest(Dsl_strRoeProt.udtRoeTxPduRef);
    break;
  /*! If Roe protocol status is PROCESSING */
  case u8ST_ROE_PROT_PROCESSING:
    /*! Raise cancel bit of the Roe protocol */
    Dsl_strRoeProt.udtMsgContext.msgAddInfo.cancelOperation = TRUE;
    break;
  /*! Else if other Roe protocol status */
  default:
    /*! Set the Roe protocol status to IDLE */
    udtReturn = E_NOT_OK;
    break;
  }

  /*! If cancellation fails */
  if(udtReturn != E_OK)
  {
    /*! Call vidEndOfRoeMsgExec() */
    vidEndOfRoeMsgExec();
  }

  /*! Call DspInternal_vidCancelRoeTransmissions() */
  DspInternal_vidCancelRoeTransmissions();
}
#endif
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Cancels the periodic protocol context(s)
    \return      void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidCancelPeriodicContext(void)
{
  uint8          u8PeriodicProtArrIdx;
  Std_ReturnType udtReturn = E_OK;

  /* !Deviation : Inhibit MISRA rule [2465]: For Loop Only executed once
                  because it is dependent on the configuration                */
  /* PRQA S 2465 ++                                                           */
  /*! For all periodic transmissions */
  for(u8PeriodicProtArrIdx = 0;
      u8PeriodicProtArrIdx < DCM_u8MAX_NUM_PERIODIC_TX;
      u8PeriodicProtArrIdx++)
  {
    /* PRQA S 2465 --                                                         */
    switch(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus)
    {
    /*! If Periodic protocol status is TX_IN_PROGRESS */
    case u8ST_PERIODIC_PROT_TX_IN_PROGRESS:
      /*! Set the Periodic protocol status to WAIT_CANCEL_TX */
      Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus =
          u8ST_PERIODIC_PROT_WAIT_CANCEL_TX;
      /*! Call PduR_DcmCancelTransmitRequest() */
      udtReturn = PduR_DcmCancelTransmitRequest(
          Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtPeriodicTxPduRef);
      break;
    /*! If Periodic protocol status is PROCESSING */
    case u8ST_PERIODIC_PROT_PROCESSING:
      /*! Raise cancel bit of the Periodic protocol */
      Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtMsgContext.msgAddInfo.
          cancelOperation = TRUE;
      break;
    /*! Else if other Periodic protocol status */
    default:
      /*! Set the Periodic protocol status to IDLE */
      udtReturn = E_NOT_OK;
      break;
    }
    /*! If cancellation fails */
    if(udtReturn != E_OK)
    {
      udtReturn = E_OK;
      /*! Call vidEndOfPeriodicMsgExec() */
      vidEndOfPeriodicMsgExec(u8PeriodicProtArrIdx);
    }
  }

  /*! Call DspInternal_vidCancelPeriodicTransmissions() */
  DspInternal_vidCancelPeriodicTransmissions();
}
#endif
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Executes protocol preemption process
    \return      void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidExecutePreemption(void)
{
  Std_ReturnType udtReturn;

  /* Dcm459 */
  /*! Call u8StopProtocol() with the main protocol index */
  udtReturn = u8StopProtocol(Dsl_u8MainProtocolIndex);

  /*! If return value is E_OK */
  if(udtReturn == E_OK)
  {
    /* Dcm147 */
    /*! Call BswM_Dcm_RequestSessionMode() with the default session */
    BswM_Dcm_RequestSessionMode(DCM_DEFAULT_SESSION);
  }

  if((udtReturn == E_OK) && (Dcm_u8eRequestedSesMode == DCM_DEFAULT_SESSION))
  {
    Dsl_bPreemptionInProgress = TRUE;

    vidCancelMainContext();

    #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
    vidCancelPeriodicContext();
    #endif

    #if(DCM_bROE_ENABLED == STD_ON)
    vidCancelRoeContext();
    #endif
  }
}
#endif
#if(DCM_bROE_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Copies ROE response from ROE protocol TX buffer
    \return BUFREQ_OK: Copy is done successfully
            BUFREQ_E_NOT_OK: Copy fails
 *  \param[in] DcmTxPduId TxPduRef of the ROE protocol  \n
 *  \Range     0..65535 \n
 *  \param[in] PduInfoPtr Pointer to the PduInfo \n
 *  \Range     Not Null \n
 *  \param[in] TxDataCntPtr Pointer to count of TX Data remaining in TX buffer\n
 *  \Range     Not Null \n
*******************************************************************************/
static FUNC(BufReq_ReturnType, DCM_CODE) udtRoeCopyFromTxBuffer(
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr)
{
  uint8             u8TxBufferId;
  PduLengthType     udtRemainingDataLen;
  PduLengthType     udtCopiedDataLen;
  PduLengthType     udtSduDataIdx;
  uint8             u8TransType;
  BufReq_ReturnType udtReturn = BUFREQ_OK;

  u8TransType = u8PROT_TRANS_TYPE(Dsl_strRoeProt.u8RoeProtIndex);

  if(u8TransType == DCM_PROTOCOL_TYPE1)
  {
    /*! Get the TX Buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
  }
  else
  {
    /*! Get the TX Buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(Dsl_strRoeProt.u8RoeProtIndex);
  }

  /*! If PduInfoPtr->SduLength is not 0 */
  if(PduInfoPtr->SduLength != (PduLengthType)0)
  {
    /*! Get data length remaining in the buffer */
    udtRemainingDataLen = (PduLengthType)
        (Dsl_strRoeProt.udtMsgContext.resDataLen -
         Dsl_astrBufferInfo[u8TxBufferId].udtIndex);
    /*! If there is data remaining in the buffer */
    if(udtRemainingDataLen > (PduLengthType)0)
    {
      /* Dcm346 */
      /*! If the remaining data length is larger than or equals
       *  PduInfoPtr->SduLength */
      if(udtRemainingDataLen >= PduInfoPtr->SduLength)
      {
        /*! Data length to be copied equals PduInfoPtr->SduLength */
        udtCopiedDataLen = PduInfoPtr->SduLength;
      }
      /*! Else */
      else
      {
        /*! Data length to be copied equals data remaining in the buffer */
        udtCopiedDataLen = udtRemainingDataLen;
      }

      /*! Copy the data from the TX buffer into PduInfoPtr->SduDataPtr */
      for(udtSduDataIdx = (PduLengthType)0;
          udtSduDataIdx < udtCopiedDataLen;
          udtSduDataIdx++)
      {
        PduInfoPtr->SduDataPtr[udtSduDataIdx] =
          Dcm_kstreDslConfig.
          astrDcmDslBuffer[u8TxBufferId].
          pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                     udtSduDataIdx];
      }

      /*! Increase the TX buffer index by the length of the copied data */
      Dsl_astrBufferInfo[u8TxBufferId].udtIndex =
        Dsl_astrBufferInfo[u8TxBufferId].udtIndex + udtCopiedDataLen;
    }
    /*! Else if there is no data remaining in the buffer */
    else
    {
      /*! Return BUFREQ_E_NOT_OK */
      udtReturn = BUFREQ_E_NOT_OK;
    }
  }

  /*! Set value of TxDataCntPtr with Dsl_strRoeProt.udtMsgContext.resDataLen
   *  minus the TX buffer index  */
  *TxDataCntPtr = (PduLengthType)
      (Dsl_strRoeProt.udtMsgContext.resDataLen -
          Dsl_astrBufferInfo[u8TxBufferId].udtIndex);

  return udtReturn;
}
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Copies paged ROE response from ROE protocol TX buffer
    \return BUFREQ_OK: Copy is done successfully
            BUFREQ_E_NOT_OK: Copy fails
 *  \param[in] PduInfoPtr Pointer to the PduInfo \n
 *  \Range     Not Null \n
 *  \param[in] TxDataCntPtr Pointer to count of TX Data remaining in TX buffer\n
 *  \Range     Not Null \n
*******************************************************************************/
static FUNC(BufReq_ReturnType, DCM_CODE) udtRoePageCopyFromTxBuffer(
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr)
{
  uint8             u8TxBufferId;
  uint8             u8TransType;
  PduLengthType     udtCopiedDataLen = (PduLengthType)0;
  PduLengthType     udtTotRemainingDataLen;
  PduLengthType     udtAvailableDataLen;
  PduLengthType     udtResidueBufferIdx;
  BufReq_ReturnType udtReturn = BUFREQ_OK;

  u8TransType = u8PROT_TRANS_TYPE(Dsl_strRoeProt.u8RoeProtIndex);

  if(u8TransType == DCM_PROTOCOL_TYPE1)
  {
    /*! Get the TX Buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
  }
  else
  {
    /*! Get the TX Buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(Dsl_strRoeProt.u8RoeProtIndex);
  }

  /*! If PduInfoPtr->SduLength is not 0 */
  if(PduInfoPtr->SduLength != (PduLengthType)0)
  {
    /*! Copy the TX buffer data into the PduInfoPtr->Buffer */
    /*! Get the remaining data length in the TX buffer */
    udtTotRemainingDataLen =
        (PduLengthType)(Dsl_strRoeProt.udtMsgContext.resDataLen -
        Dsl_udtRoeTotalPageCopiedLen);

    /*! If remaining data length of the total response is larger than 0 */
    if(udtTotRemainingDataLen > (PduLengthType)0)
    {
      /*! Get length of data remaining in the current page */
      udtAvailableDataLen = (PduLengthType)(
          (Dsl_udtRoeFilledPageLen
          + Dsl_udtRoePageResidueBuffIdx)
          - Dsl_astrBufferInfo[u8TxBufferId].udtIndex);

      /*! If there is enough data in the current page to be copied into
       *  the PduR buffer */
      if(udtAvailableDataLen >= PduInfoPtr->SduLength)
      {
        /*! Set copied data length with PduInfoPtr->SduLength */
        udtCopiedDataLen = PduInfoPtr->SduLength;
      }
      /*! Else if the data in the current page is not enough for the
       *  data length requested by the PduR */
      else
      {
        /*! If the data remaining in the current page equals the data
         *  remaining in the total response (which means the current page
         *  is the last page) */
        if(udtAvailableDataLen == udtTotRemainingDataLen)
        {
          /*! Set the copied data length to the length of data remaining in
           *  the current page */
          udtCopiedDataLen = udtAvailableDataLen;
        }
        /*! Else if the data remaining in the current page is less than
         *  data remaining in the total response */
        else
        {
          /*! Buffer the page residue */
          for(udtResidueBufferIdx = 0;
              udtResidueBufferIdx <
              (PduLengthType)(Dsl_udtRoeFilledPageLen
                            - Dsl_astrBufferInfo[u8TxBufferId].udtIndex);
              udtResidueBufferIdx++)
          {
            Dsl_au8RoePageResidueBuffer[udtResidueBufferIdx +
                                     Dsl_udtRoePageResidueBuffIdx] =
             Dcm_kstreDslConfig.
             astrDcmDslBuffer[u8TxBufferId].
             pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                        udtResidueBufferIdx];
          }
          /*! Update the residue buffer index with the residue length */
          Dsl_udtRoePageResidueBuffIdx +=
              Dsl_udtRoeFilledPageLen
              - Dsl_astrBufferInfo[u8TxBufferId].udtIndex;
          /*! Reset the TX buffer index to 0 */
          Dsl_astrBufferInfo[u8TxBufferId].udtIndex = (Dcm_MsgLenType)0;
          /*! Set the main protocol status to PAGE_UPDATE_REQUESTED */
          Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_PAGE_UPDATE_REQUESTED;
          /*! Call DsdInternal_UpdatePage() to request a new page */
          DsdInternal_UpdatePage((Dcm_IdContextType)1);
          /*! Return BUFREQ_E_BUSY */
          udtReturn = BUFREQ_E_BUSY;
        }
      }

      /*! If no page update is requested */
      if(udtReturn == BUFREQ_OK)
      {
        /*! Call vidRoeCopyData() */
        vidRoeCopyData(u8TxBufferId, PduInfoPtr, udtCopiedDataLen);
      }
    }
    /*! Else if there is no remaining data in the TX buffer */
    else
    {
      /*! Return BUFREQ_E_NOT_OK */
      udtReturn = BUFREQ_E_NOT_OK;
    }
  }
  /*! Set value of TxDataCntPtr with the remaining data length of the
   *  total response */
  *TxDataCntPtr = (PduLengthType)(Dsl_strRoeProt.udtMsgContext.resDataLen -
                  Dsl_udtRoeTotalPageCopiedLen);

  return udtReturn;
}
/******************************************************************************/
/*! \Description Copies Roe TX data
    \return      void
 *  \param[in] udtCopiedDataLen Copied Data Length  \n
 *  \Range     Range if type PduLengthType \n
*******************************************************************************/
static FUNC(void, DCM_CODE) vidRoeCopyData(
    uint8 u8TxBufferId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    PduLengthType udtCopiedDataLen)
{
  PduLengthType     udtSduDataIdx;

  /*! If the data to be copied is less than or equals the length of
   *  the residue */
  if(udtCopiedDataLen <= Dsl_udtRoePageResidueBuffIdx)
  {
    /*! Copy the residue into the PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < udtCopiedDataLen;
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr[udtSduDataIdx] =
          Dsl_au8RoePageResidueBuffer[udtSduDataIdx];
    }
    /*! Shift up the data in the residue buffer by the copied data
     *  length */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < (Dsl_udtRoePageResidueBuffIdx -
                         udtCopiedDataLen);
        udtSduDataIdx++)
    {
      Dsl_au8RoePageResidueBuffer[udtSduDataIdx] =
          Dsl_au8RoePageResidueBuffer[udtSduDataIdx+udtCopiedDataLen];
    }
    /*! Decrement the residue index by the length of data copied */
    Dsl_udtRoePageResidueBuffIdx -= udtCopiedDataLen;
  }
  /*! Else if data to be copied is longer than residue data */
  else
  {
    /*! Copy all the residue data into the PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < Dsl_udtRoePageResidueBuffIdx;
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr[udtSduDataIdx] =
          Dsl_au8RoePageResidueBuffer[udtSduDataIdx];
    }
    /*! Copy the rest of request data from the TX buffer into the
     *  PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < (udtCopiedDataLen -
                         Dsl_udtRoePageResidueBuffIdx);
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr[udtSduDataIdx +
                             Dsl_udtRoePageResidueBuffIdx] =
        Dcm_kstreDslConfig.
        astrDcmDslBuffer[u8TxBufferId].
        pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                   udtSduDataIdx];
    }
    /*! Increase the TX buffer index with the copied data length */
    Dsl_astrBufferInfo[u8TxBufferId].udtIndex +=
          udtCopiedDataLen - Dsl_udtRoePageResidueBuffIdx;
    /*! Reset the residue buffer index to 0 */
    Dsl_udtRoePageResidueBuffIdx = 0;
  }
  /*! Update the length of the total response copied */
  Dsl_udtRoeTotalPageCopiedLen += udtCopiedDataLen;
}
#endif
#endif
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Copies periodic response from periodic protocol TX buffer
    \return BUFREQ_OK: Copy is done successfully
            BUFREQ_E_NOT_OK: Copy fails
 *  \param[in] u8PeriodicProtIdx periodic protocol index  \n
 *  \Range     0..65535 \n
 *  \param[in] PduInfoPtr Pointer to the PduInfo \n
 *  \Range     Not Null \n
 *  \param[in] TxDataCntPtr Pointer to count of TX Data remaining in TX buffer\n
 *  \Range     Not Null \n
*******************************************************************************/
static FUNC(BufReq_ReturnType, DCM_CODE) udtPeriodicCopyFromTxBuffer(
    uint8 u8PeriodicProtArrIdx,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr)
{
  uint8             u8TxBufferId;
  PduLengthType     udtRemainingDataLen;
  PduLengthType     udtCopiedDataLen;
  PduLengthType     udtSduDataIdx;
  uint8             u8TransType;
  BufReq_ReturnType udtReturn = BUFREQ_OK;

  /*! Get the TransType of the periodic protocol */
  u8TransType = u8PROT_TRANS_TYPE(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].
      u8PeriodicProtIndex);

  if(u8TransType == DCM_PROTOCOL_TYPE1)
  {
    /*! Get the TX buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
  }
  else
  {
    /*! Get the TX buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].
        u8PeriodicProtIndex);
  }

  /*! If PduInfoPtr->SduLength is not 0 */
  if(PduInfoPtr->SduLength != (PduLengthType)0)
  {
    /*! Get length of data remaining in the buffer */
    udtRemainingDataLen = (PduLengthType)
        (Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtMsgContext.resDataLen -
         Dsl_astrBufferInfo[u8TxBufferId].udtIndex);

    /*! If there is data remaining in the buffer */
    if(udtRemainingDataLen > (PduLengthType)0)
    {
      /* Dcm346 */
      /*! If the remaining data length is larger than or equals
       *  PduInfoPtr->SduLength */
      if(udtRemainingDataLen >= PduInfoPtr->SduLength)
      {
        /*! Set copied data length to PduInfoPtr->SduLength */
        udtCopiedDataLen = PduInfoPtr->SduLength;
      }
      /*! Else */
      else
      {
        /*! Set copied data length to the length of data remaining in the
         *  buffer */
        udtCopiedDataLen = udtRemainingDataLen;
      }

      /*! Copy the data from the TX buffer into PduInfoPtr->SduDataPtr */
      for(udtSduDataIdx = (PduLengthType)0;
          udtSduDataIdx < udtCopiedDataLen;
          udtSduDataIdx++)
      {
        PduInfoPtr->SduDataPtr[udtSduDataIdx] =
          Dcm_kstreDslConfig.
          astrDcmDslBuffer[u8TxBufferId].
          pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                     udtSduDataIdx];
      }

      /*! Increase the TX buffer index by the length of the copied data */
      Dsl_astrBufferInfo[u8TxBufferId].udtIndex =
        Dsl_astrBufferInfo[u8TxBufferId].udtIndex + udtCopiedDataLen;
    }
    /*! Else if there is no data remaining in the buffer */
    else
    {
      /*! Return BUFREQ_E_NOT_OK */
      udtReturn = BUFREQ_E_NOT_OK;
    }
  }

  /*! Set value of TxDataCntPtr with Dsl_strRoeProt.udtMsgContext.resDataLen
   *  minus the TX buffer index  */
  *TxDataCntPtr = (PduLengthType)
      (Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtMsgContext.resDataLen -
      Dsl_astrBufferInfo[u8TxBufferId].udtIndex);

  return udtReturn;
}
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Copies periodic response from periodic protocol TX buffer
    \return BUFREQ_OK: Copy is done successfully
            BUFREQ_E_NOT_OK: Copy fails
 *  \param[in] u8PeriodicProtArrIdx periodic protocol index  \n
 *  \Range     0..65535 \n
 *  \param[in] PduInfoPtr Pointer to the PduInfo \n
 *  \Range     Not Null \n
 *  \param[in] TxDataCntPtr Pointer to count of TX Data remaining in TX buffer\n
 *  \Range     Not Null \n
*******************************************************************************/
static FUNC(BufReq_ReturnType, DCM_CODE) udtPeriodicPageCopyFromTxBuffer(
    uint8 u8PeriodicProtArrIdx,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr)
{
  uint8             u8TxBufferId;
  uint8             u8TransType;
  PduLengthType     udtCopiedDataLen = (PduLengthType)0;
  PduLengthType     udtTotRemainingDataLen;
  PduLengthType     udtAvailableDataLen;
  PduLengthType     udtResidueBufferIdx;
  uint8             u8PeriodicProtIdx;
  BufReq_ReturnType udtReturn = BUFREQ_OK;

  u8PeriodicProtIdx = Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].
      u8PeriodicProtIndex;

  u8TransType = u8PROT_TRANS_TYPE(u8PeriodicProtIdx);

  if(u8TransType == DCM_PROTOCOL_TYPE1)
  {
    /*! Get the TX Buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
  }
  else
  {
    /*! Get the TX Buffer Id */
    u8TxBufferId = u8TX_BUFFER_ID(u8PeriodicProtIdx);
  }

  /*! If PduInfoPtr->SduLength is not 0 */
  if(PduInfoPtr->SduLength != (PduLengthType)0)
  {
    /*! Copy the TX buffer data into the PduInfoPtr->Buffer */
    /*! Get the remaining data length in the TX buffer */
    udtTotRemainingDataLen =
        (PduLengthType)(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].
            udtMsgContext.resDataLen -
            Dsl_audtPeriodTotalPageCopiedLen[u8PeriodicProtArrIdx]);

    /*! If remaining data length of the total response is larger than 0 */
    if(udtTotRemainingDataLen > (PduLengthType)0)
    {
      /*! Get length of data remaining in the current page */
      udtAvailableDataLen = (PduLengthType)(
          (Dsl_audtPeriodFilledPageLen[u8PeriodicProtArrIdx]
          + Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx])
          - Dsl_astrBufferInfo[u8TxBufferId].udtIndex);

      /*! If there is enough data in the current page to be copied into
       *  the PduR buffer */
      if(udtAvailableDataLen >= PduInfoPtr->SduLength)
      {
        /*! Set copied data length with PduInfoPtr->SduLength */
        udtCopiedDataLen = PduInfoPtr->SduLength;
      }
      /*! Else if the data in the current page is not enough for the
       *  data length requested by the PduR */
      else
      {
        /*! If the data remaining in the current page equals the data
         *  remaining in the total response (which means the current page
         *  is the last page) */
        if(udtAvailableDataLen == udtTotRemainingDataLen)
        {
          /*! Set the copied data length to the length of data remaining in
           *  the current page */
          udtCopiedDataLen = udtAvailableDataLen;
        }
        /*! Else if the data remaining in the current page is less than
         *  data remaining in the total response */
        else
        {
          /*! Buffer the page residue */
          for(udtResidueBufferIdx = 0;
              udtResidueBufferIdx < (PduLengthType)
              (Dsl_audtPeriodFilledPageLen[u8PeriodicProtArrIdx]
               - Dsl_astrBufferInfo[u8TxBufferId].udtIndex);
              udtResidueBufferIdx++)
          {
            Dsl_au8PeriodPageResidueBuff[u8PeriodicProtArrIdx]
             [udtResidueBufferIdx +
              Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx]] =
             Dcm_kstreDslConfig.
             astrDcmDslBuffer[u8TxBufferId].
             pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                        udtResidueBufferIdx];
          }
          /*! Update the residue buffer index with the residue length */
          Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx] +=
             Dsl_audtPeriodFilledPageLen[u8PeriodicProtArrIdx]
             - Dsl_astrBufferInfo[u8TxBufferId].udtIndex;
          /*! Reset the TX buffer index to 0 */
          Dsl_astrBufferInfo[u8TxBufferId].udtIndex = 0;
          /*! Set the main protocol status to PAGE_UPDATE_REQUESTED */
          Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus =
              u8ST_PERIODIC_PROT_PAGE_UPDATE_REQUESTED;
          /*! Call DsdInternal_UpdatePage() to request a new page */
          #if(DCM_bROE_ENABLED == STD_ON)
          DsdInternal_UpdatePage((Dcm_IdContextType)(u8PeriodicProtArrIdx + 2));
          #else
          DsdInternal_UpdatePage((Dcm_IdContextType)(u8PeriodicProtArrIdx + 1));
          #endif
          /*! Return BUFREQ_E_BUSY */
          udtReturn = BUFREQ_E_BUSY;
        }
      }

      /*! If no page update is requested */
      if(udtReturn == BUFREQ_OK)
      {
        /*! Call vidPeriodicCopyData() */
        vidPeriodicCopyData(u8PeriodicProtArrIdx, u8TxBufferId,
                            PduInfoPtr, udtCopiedDataLen);
      }
    }
    /*! Else if there is no remaining data in the TX buffer */
    else
    {
      /*! Return BUFREQ_E_NOT_OK */
      udtReturn = BUFREQ_E_NOT_OK;
    }
  }
  /*! Set value of TxDataCntPtr with the remaining data length of the
   *  total response */
  *TxDataCntPtr = (PduLengthType)(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].
      udtMsgContext.resDataLen -
      Dsl_audtPeriodTotalPageCopiedLen[u8PeriodicProtArrIdx]);

  return udtReturn;
}
/******************************************************************************/
/*! \Description Copies Periodic TX data
    \return      void
 *  \param[in] udtCopiedDataLen Copied Data Length  \n
 *  \Range     Range if type PduLengthType \n
*******************************************************************************/
static FUNC(void, DCM_CODE) vidPeriodicCopyData(
    uint8 u8PeriodicProtArrIdx,
    uint8 u8TxBufferId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    PduLengthType udtCopiedDataLen)
{
  PduLengthType     udtSduDataIdx;

  /*! If the data to be copied is less than or equals the length of
   *  the residue */
  if(udtCopiedDataLen <=
      Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx])
  {
    /*! Copy the residue into the PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < udtCopiedDataLen;
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr[udtSduDataIdx] =
          Dsl_au8PeriodPageResidueBuff[u8PeriodicProtArrIdx]
                                          [udtSduDataIdx];
    }
    /*! Shift up the data in the residue buffer by the copied data
     *  length */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx <
        (Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx] -
                         udtCopiedDataLen);
        udtSduDataIdx++)
    {
      Dsl_au8PeriodPageResidueBuff[u8PeriodicProtArrIdx]
                                      [udtSduDataIdx] =
      Dsl_au8PeriodPageResidueBuff[u8PeriodicProtArrIdx]
                                      [udtSduDataIdx+udtCopiedDataLen];
    }
    /*! Decrement the residue index by the length of data copied */
    Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx] -=
        udtCopiedDataLen;
  }
  /*! Else if data to be copied is longer than residue data */
  else
  {
    /*! Copy all the residue data into the PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx <
        Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx];
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr[udtSduDataIdx] =
          Dsl_au8PeriodPageResidueBuff[u8PeriodicProtArrIdx]
                                          [udtSduDataIdx];
    }
    /*! Copy the rest of request data from the TX buffer into the
     *  PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < (udtCopiedDataLen -
            Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx]);
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr
      [udtSduDataIdx +
       Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx]] =
        Dcm_kstreDslConfig.
        astrDcmDslBuffer[u8TxBufferId].
        pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                   udtSduDataIdx];
    }
    /*! Increase the TX buffer index with the copied data length */
    Dsl_astrBufferInfo[u8TxBufferId].udtIndex +=
        udtCopiedDataLen -
        Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx];
    /*! Reset the residue buffer index to 0 */
    Dsl_audtPeriodPageResidueBuffIdx[u8PeriodicProtArrIdx] = 0;
  }
  /*! Update the length of the total response copied */
  Dsl_audtPeriodTotalPageCopiedLen[u8PeriodicProtArrIdx] +=
      udtCopiedDataLen;
}
#endif
#endif
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Copies Main protocol paged response from main protocol TX
 *               buffer
    \return BUFREQ_OK: Copy is done successfully
            BUFREQ_E_NOT_OK: Copy fails
 *  \param[in] DcmTxPduId TxPduRef of the main protocol  \n
 *  \Range     0..65535 \n
 *  \param[in] PduInfoPtr Pointer to the PduInfo \n
 *  \Range     Not Null \n
 *  \param[in] TxDataCntPtr Pointer to count of TX Data remaining in the page\n
 *  \Range     Not Null \n
*******************************************************************************/
static FUNC(BufReq_ReturnType, DCM_CODE) udtMainPageCopyFromTxBuffer(
    PduIdType DcmTxPduId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr)
{
  uint8             u8ProtocolTxIdx;
  boolean           bTxPduIdFound = FALSE;
  uint8             u8ProtocolIdx;
  uint8             u8TxBufferId;
  PduLengthType     udtTotRemainingDataLen;
  PduLengthType     udtCopiedDataLen = (PduLengthType)0;
  PduLengthType     udtAvailableDataLen;
  PduLengthType     udtResidueBufferIdx;
  BufReq_ReturnType udtReturn = BUFREQ_OK;

  /*! Search for the TxPduRef in the configured protocols */
  for(u8ProtocolTxIdx = (uint8)0;
     (u8ProtocolTxIdx <
         Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslNumProtocolTx)
  && (bTxPduIdFound == FALSE);
     u8ProtocolTxIdx++)
  {
    /*! If found */
    if(Dcm_pkstrePbConfig->strPbDcmDslConfig.
        pkstrDcmDslProtocolTx[u8ProtocolTxIdx].udtDcmDslProtocolTxPduRef
        == DcmTxPduId)
    {
      bTxPduIdFound = TRUE;

      /*! Get the protocol index */
      u8ProtocolIdx = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                      pkstrDcmDslProtocolTx[u8ProtocolTxIdx].
                      u8DcmDslProtocolIndex;

      /*! Get the TX buffer ID */
      u8TxBufferId = u8TX_BUFFER_ID(u8ProtocolIdx);

      /*! If PduInfoPtr->SduLength is not 0 */
      if(PduInfoPtr->SduLength != (PduLengthType)0)
      {
        /*! Copy the TX buffer data into the PduInfoPtr->Buffer */
        /*! Get the remaining data length in the TX buffer */
        udtTotRemainingDataLen =
            (PduLengthType)(Dsl_strMainProtMsgContext.resDataLen -
            Dsl_udtMnTotalPageCopiedLen);

        /*! If remaining data length of the total response is larger than 0 */
        if(udtTotRemainingDataLen > (PduLengthType)0)
        {
          /*! Get length of data remaining in the current page */
          udtAvailableDataLen = (PduLengthType)(
              (Dsl_udtMainFilledPageLen
              + Dsl_udtMnPageResidueBuffIdx)
              - Dsl_astrBufferInfo[u8TxBufferId].udtIndex);

          /*! If there is enough data in the current page to be copied into
           *  the PduR buffer */
          if(udtAvailableDataLen >= PduInfoPtr->SduLength)
          {
            /*! Set copied data length with PduInfoPtr->SduLength */
            udtCopiedDataLen = PduInfoPtr->SduLength;
          }
          /*! Else if the data in the current page is not enough for the
           *  data length requested by the PduR */
          else
          {
            /*! If the data remaining in the current page equals the data
             *  remaining in the total response (which means the current page
             *  is the last page) */
            if(udtAvailableDataLen == udtTotRemainingDataLen)
            {
              /*! Set the copied data length to the length of data remaining in
               *  the current page */
              udtCopiedDataLen = udtAvailableDataLen;
            }
            /*! Else if the data remaining in the current page is less than
             *  data remaining in the total response */
            else
            {
              /*! Buffer the page residue */
              for(udtResidueBufferIdx = 0;
                  udtResidueBufferIdx <
                  (PduLengthType)(Dsl_udtMainFilledPageLen
                                - Dsl_astrBufferInfo[u8TxBufferId].udtIndex);
                  udtResidueBufferIdx++)
              {
                Dsl_au8MnPageResidueBuffer[udtResidueBufferIdx +
                                         Dsl_udtMnPageResidueBuffIdx] =
                 Dcm_kstreDslConfig.
                 astrDcmDslBuffer[u8TxBufferId].
                 pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                            udtResidueBufferIdx];
              }
              /*! Update the residue buffer index with the residue length */
              Dsl_udtMnPageResidueBuffIdx +=
                  Dsl_udtMainFilledPageLen
                  - Dsl_astrBufferInfo[u8TxBufferId].udtIndex;
              /*! Reset the TX buffer index to 0 */
              Dsl_astrBufferInfo[u8TxBufferId].udtIndex = 0;
              /*! Set the main protocol status to PAGE_UPDATE_REQUESTED */
              Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PAGE_UPDATE_REQUESTED;
              /*! Call DsdInternal_UpdatePage() to request a new page */
              DsdInternal_UpdatePage(DspInternal_u8DSL_MAIN_PROT_CONTEXT);
              /*! Return BUFREQ_E_BUSY */
              udtReturn = BUFREQ_E_BUSY;
            }
          }

          /*! If no page update is requested */
          if(udtReturn == BUFREQ_OK)
          {
            /*! Call vidMainPageCopyData() */
            vidMainPageCopyData(u8TxBufferId,PduInfoPtr, udtCopiedDataLen);
          }
        }
        /*! Else if there is no remaining data in the TX buffer */
        else
        {
          /*! Return BUFREQ_E_NOT_OK */
          udtReturn = BUFREQ_E_NOT_OK;
        }
      }
      /*! Set value of TxDataCntPtr with the remaining data length of the
       *  total response */
      *TxDataCntPtr = (PduLengthType)(Dsl_strMainProtMsgContext.resDataLen -
                      Dsl_udtMnTotalPageCopiedLen);
    }
  }

  return udtReturn;
}
/******************************************************************************/
/*! \Description Copies Main protocol TX data
    \return      void
 *  \param[in] udtCopiedDataLen Copied Data Length  \n
 *  \Range     Range if type PduLengthType \n
*******************************************************************************/
static FUNC(void, DCM_CODE) vidMainPageCopyData(
    uint8 u8TxBufferId,
    P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    PduLengthType udtCopiedDataLen)
{
  PduLengthType     udtSduDataIdx;

  /*! If the data to be copied is less than or equals the length of
   *  the residue */
  if(udtCopiedDataLen <= Dsl_udtMnPageResidueBuffIdx)
  {
    /*! Copy the residue into the PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < udtCopiedDataLen;
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr[udtSduDataIdx] =
          Dsl_au8MnPageResidueBuffer[udtSduDataIdx];
    }
    /*! Shift up the data in the residue buffer by the copied data
     *  length */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < (Dsl_udtMnPageResidueBuffIdx -
                         udtCopiedDataLen);
        udtSduDataIdx++)
    {
      Dsl_au8MnPageResidueBuffer[udtSduDataIdx] =
          Dsl_au8MnPageResidueBuffer[udtSduDataIdx+udtCopiedDataLen];
    }
    /*! Decrement the residue index by the length of data copied */
    Dsl_udtMnPageResidueBuffIdx -= udtCopiedDataLen;
  }
  /*! Else if data to be copied is longer than residue data */
  else
  {
    /*! Copy all the residue data into the PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < Dsl_udtMnPageResidueBuffIdx;
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr[udtSduDataIdx] =
          Dsl_au8MnPageResidueBuffer[udtSduDataIdx];
    }
    /*! Copy the rest of request data from the TX buffer into the
     *  PduR buffer */
    for(udtSduDataIdx = (PduLengthType)0;
        udtSduDataIdx < (udtCopiedDataLen -
                         Dsl_udtMnPageResidueBuffIdx);
        udtSduDataIdx++)
    {
      PduInfoPtr->SduDataPtr[udtSduDataIdx +
                             Dsl_udtMnPageResidueBuffIdx] =
        Dcm_kstreDslConfig.
        astrDcmDslBuffer[u8TxBufferId].
        pudtBuffer[Dsl_astrBufferInfo[u8TxBufferId].udtIndex +
                   udtSduDataIdx];
    }
    /*! Increase the TX buffer index with the copied data length */
    Dsl_astrBufferInfo[u8TxBufferId].udtIndex +=
        udtCopiedDataLen - Dsl_udtMnPageResidueBuffIdx;
    /*! Reset the residue buffer index to 0 */
    Dsl_udtMnPageResidueBuffIdx = 0;
  }
  /*! Update the length of the total response copied */
  Dsl_udtMnTotalPageCopiedLen += udtCopiedDataLen;
}
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Handles the Periodic Transmissions of TYPE1 pending on the
 *               main protocol status to be IDLE
    \return      void
    \Trace_To
*******************************************************************************/
static FUNC(void, DCM_CODE) vidHandleTyp1PeriodicTx(void)
{
  uint8               u8PeriodicTxBufferId;
  uint8               u8PeriodicRxBufferId;
  uint8               u8TransType;
  uint8               u8ConnRef;
  uint8               u8PeriodicProtIdx;
  Dcm_MsgContextType* pstrPeriodicMsgContext;

  /*! Get the connection reference of the main protocol RxPduId */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);
  /*! If the periodic transmission container exists */
  if(pkstrPERIODIC_TRANS_PTR(Dsl_u8MainProtocolIndex,u8ConnRef)
      != (Dcm_DslPeriodicTransmissionType*)NULL_PTR)
  {
    /*! Get the periodic protocol index. */
    u8PeriodicProtIdx = u8PERIODIC_PROT_IDX(Dsl_u8MainProtocolIndex, u8ConnRef);
    /*! Get the periodic protocol TransType */
    u8TransType = u8PROT_TRANS_TYPE(u8PeriodicProtIdx);

    /*! If the periodic protocol TransType is TYPE1 and the periodic protocol
     *  status is PROCESS_PENDING */
    if((u8TransType == DCM_PROTOCOL_TYPE1)
     &&(Dsl_astrPeriodicProt[0].udtProtStatus ==
        u8ST_PERIODIC_PROT_PROCESS_PENDING))
    {
      /*! Get the periodic TX/RX buffer Id's */
      u8PeriodicTxBufferId = u8TX_BUFFER_ID(u8PeriodicProtIdx);
      u8PeriodicRxBufferId = u8RX_BUFFER_ID(u8PeriodicProtIdx);

      /*! Set 1st byte of the periodic protocol RX buffer with 0x22 */
      Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicRxBufferId].
      pudtBuffer[0] = 0x22;
      /*! Set 2nd byte of the periodic protocol RX buffer with 0xF2 */
      Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicRxBufferId].
      pudtBuffer[1] = 0xF2;
      /*! Set 3rd byte of the periodic protocol RX buffer with
       *  u8PeriodicId */
      Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicRxBufferId].
      pudtBuffer[2] = Dsl_u8PendingPeriodicId;

      /*! Get a pointer to the periodic TX message context */
      pstrPeriodicMsgContext = &Dsl_astrPeriodicProt[0].udtMsgContext;

      /*! Fill the periodic TX message context */
      pstrPeriodicMsgContext->reqData            =
          Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicRxBufferId].pudtBuffer;
      pstrPeriodicMsgContext->reqDataLen         = 3;
      pstrPeriodicMsgContext->resData            =
          Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicTxBufferId].pudtBuffer;
      pstrPeriodicMsgContext->resMaxDataLen      =
        Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicTxBufferId].udtBufferSize;
      pstrPeriodicMsgContext->dcmRxPduId         =
          Dsl_udtMainProtRxPduId;
      #if(DCM_bROE_ENABLED == STD_ON)
      pstrPeriodicMsgContext->idContext          = (Dcm_IdContextType)2;
      #else
      pstrPeriodicMsgContext->idContext          = (Dcm_IdContextType)1;
      #endif
      pstrPeriodicMsgContext->msgAddInfo.reqType =
       (u8RX_ADDR_TYPE(Dsl_udtMainProtRxPduId) == DCM_PHYS_ADDR) ? FALSE : TRUE;
      pstrPeriodicMsgContext->msgAddInfo.cancelOperation = FALSE;

      /*! Set the periodic protocol status to PROCESSING */
      Dsl_astrPeriodicProt[0].udtProtStatus = u8ST_PERIODIC_PROT_PROCESSING;
      Dsl_astrPeriodicProt[0].u8PeriodicProtIndex = u8PeriodicProtIdx;

      /* Dcm195 */
      /*! Lock the periodic protocol TX and RX buffers */
      Dsl_astrBufferInfo[u8PeriodicRxBufferId].udtStatus = u8ST_BUFF_LOCKED;
      Dsl_astrBufferInfo[u8PeriodicTxBufferId].udtStatus = u8ST_BUFF_LOCKED;
      /*! Call DsdInternal_DataIndication() to forward the request to the DSD */
      DsdInternal_DataIndication(pstrPeriodicMsgContext,
                                 u8SID_TABLE(u8PeriodicProtIdx));
    }
  }
}
/******************************************************************************/
/*! \Description Gets a free periodic protocol TX slot
 *  \param[in] pu8FreePeriodicTxIdx pointer in which the free index is
 *             returned \n
 *  \Range     Not Null \n
    \return    Search status:
               E_OK: if a free slot is found
               E_NOT_OK: if no free slot is found
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) udtGetFreePeriodicTxIdx(
                                                    uint8* pu8FreePeriodicTxIdx)
{
  uint8          u8Index;
  Std_ReturnType udtReturn = E_NOT_OK;

  /*! For total number of Periodic TX DCM_u8MAX_NUM_PERIODIC_TX, check the
   *  protocol status */
  /* !Deviation : Inhibit MISRA rule [2465]: For Loop Only executed once
                  because it is dependent on the configuration                */
  /* PRQA S 2465 ++                                                           */
  for(u8Index = 0; (u8Index < DCM_u8MAX_NUM_PERIODIC_TX) &&
     (udtReturn == E_NOT_OK); u8Index++)
  {
    /* PRQA S 2465 --                                                         */
    /*! If the protocol status is IDLE */
    if(Dsl_astrPeriodicProt[u8Index].udtProtStatus == u8ST_PERIODIC_PROT_IDLE)
    {
      /*! Set the value of the pointer pu8FreePeriodicTxIdx with the protocol
       *  index */
      *pu8FreePeriodicTxIdx = u8Index;
      /*! Set the return value to E_OK */
      udtReturn = E_OK;
    }
  }

  return (udtReturn);
}
/******************************************************************************/
/*! \Description Returns if there is an active TYPE1 periodic transmission
    \return      E_OK: there is an active TYPE1 periodic transmission
                 E_NOT_OK: there is no active TYPE1 periodic transmission
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) udtPeriodicTxTyp1Active(void)
{
  uint8          u8TransType;
  uint8          u8ConnRef;
  uint8          u8PeriodicProtIdx;

  /*! Set the return value to E_NOT_OK */
  Std_ReturnType udtReturn = E_NOT_OK;

  /*! Get the connection reference of the main protocol */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);

  /*! If the periodic transmission protocol container exists */
  if(pkstrPERIODIC_TRANS_PTR(Dsl_u8MainProtocolIndex,u8ConnRef)
      != (Dcm_DslPeriodicTransmissionType*)NULL_PTR)
  {
    /*! Get the periodic protocol index */
    u8PeriodicProtIdx = u8PERIODIC_PROT_IDX(Dsl_u8MainProtocolIndex, u8ConnRef);
    /*! Get the TransType of the periodic protocol */
    u8TransType = u8PROT_TRANS_TYPE(u8PeriodicProtIdx);

    /*! If the TransType is TYPE1 and Dsl_astrPeriodicProt[0].udtProtStatus is
     *  IDLE  */
    if((u8TransType == DCM_PROTOCOL_TYPE1)
     &&(Dsl_astrPeriodicProt[0].udtProtStatus != u8ST_PERIODIC_PROT_IDLE))
    {
      /*! Set the return value to E_OK */
      udtReturn = E_OK;
    }
  }
  return (udtReturn);
}
/******************************************************************************/
/*! \Description Returns if the passed TxPduRef is a periodic protocol TxPduRef
 *  \param[in] DcmTxPduId TxPduRef to be checked \n
 *  \Range     0..255 \n
 *  \param[in] pu8PeriodicProtIdx Pointer to the periodic protocol \n
 *  \Range     Not Null \n
 *  \param[in] pu8IdContext Pointer to Id Context \n
 *  \Range     Not Null \n
    \return
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) udtIsPeriodicTxPduRef(
    PduIdType DcmTxPduId,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) pu8PeriodicProtIdx)
{
  uint8          u8PeriodicTxIdx;
  Std_ReturnType udtReturn = E_NOT_OK;

  /*! For all periodic transmissions */
  /* !Deviation : Inhibit MISRA rule [2465]: For Loop Only executed once
                  because it is dependent on the configuration                */
  /* PRQA S 2465 ++                                                           */
  for(u8PeriodicTxIdx = 0;
      (u8PeriodicTxIdx < DCM_u8MAX_NUM_PERIODIC_TX)&&(udtReturn == E_NOT_OK);
      u8PeriodicTxIdx++)
  {
    /* PRQA S 2465 --                                                         */
    /*! If the periodic protocol status is TX_IN_PROGRESS and its TxPduRef
     *  equals DcmTxPduId */
    if((Dsl_astrPeriodicProt[u8PeriodicTxIdx].udtPeriodicTxPduRef == DcmTxPduId)
     &&(Dsl_astrPeriodicProt[u8PeriodicTxIdx].udtProtStatus ==
         u8ST_PERIODIC_PROT_TX_IN_PROGRESS))
    {
      /*! Return E_OK */
      udtReturn = E_OK;
      /*! Set data of pu8PeriodicProtIdx with the loop index */
      *pu8PeriodicProtIdx = u8PeriodicTxIdx;
    }
  }

  return (udtReturn);
}
/******************************************************************************/
/*! \Description Handles TxConfirmation for Type2 periodic transmission
    \return    void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidPeriodicTxConfirmation(
    PduIdType udtDcmTxPduId,
    NotifResultType udtResult)
{
  uint8              u8ConnRef;
  uint8              u8NumOfTxConfPduIds;
  uint8              u8TxConfPduIdIdx;
  Dcm_IdContextType  udtPeriodicIdContext;

  /*! Get the connection reference of the main protocol */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);

  /*! If the periodic tx container exists */
  if(pkstrPERIODIC_TRANS_PTR(Dsl_u8MainProtocolIndex,u8ConnRef)
    != (Dcm_DslPeriodicTransmissionType*)NULL_PTR)
  {
    u8NumOfTxConfPduIds = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                          pkstrDcmDslProtocolRow[Dsl_u8MainProtocolIndex].
                          ppkstrDcmDslConnection[u8ConnRef]->
                          pkstrDcmDslPeriodicTransmission->
                          u8NumOfTxConfirmPduIds;

    /*! Search the periodic protocol TxConfPduId's for the passed
     *  DcmTxPduId */
    for(u8TxConfPduIdIdx = 0;
        u8TxConfPduIdIdx < u8NumOfTxConfPduIds;
        u8TxConfPduIdIdx++)
    {
      /*! If found */
      if(Dcm_pkstrePbConfig->strPbDcmDslConfig.
         pkstrDcmDslProtocolRow[Dsl_u8MainProtocolIndex].
        ppkstrDcmDslConnection[u8ConnRef]->
        pkstrDcmDslPeriodicTransmission->
        pudtDcmDslTxConfirmPduIds[u8TxConfPduIdIdx]
        == udtDcmTxPduId)
      {
        #if(DCM_bROE_ENABLED == STD_ON)
        udtPeriodicIdContext = (uint8)(u8TxConfPduIdIdx + 2);
        #else
        udtPeriodicIdContext = (uint8)(u8TxConfPduIdIdx + 1);
        #endif

        if(Dsl_astrPeriodicProt[u8TxConfPduIdIdx].udtProtStatus ==
            u8ST_PERIODIC_PROT_TX_IN_PROGRESS)
        {
          /*! Call DsdInternal_Confirmation() with Result */
          DsdInternal_Confirmation(
              udtPeriodicIdContext,
              Dsl_astrPeriodicProt[u8TxConfPduIdIdx].udtMsgContext.dcmRxPduId,
              udtResult);
          /*! Call vidEndOfPeriodicMsgExec() */
          vidEndOfPeriodicMsgExec(u8TxConfPduIdIdx);
        }
        else if(Dsl_astrPeriodicProt[u8TxConfPduIdIdx].udtProtStatus ==
            u8ST_PERIODIC_PROT_WAIT_CANCEL_TX)
        {
          /*! Call DsdInternal_Confirmation() with Result */
          DsdInternal_Confirmation(
              udtPeriodicIdContext,
              Dsl_astrPeriodicProt[u8TxConfPduIdIdx].udtMsgContext.dcmRxPduId,
              NTFRSLT_E_NOT_OK);
          /*! Call vidEndOfPeriodicMsgExec() */
          vidEndOfPeriodicMsgExec(u8TxConfPduIdIdx);
        }
        else
        {
          /*! Do nothing */
        }
      }
    }
  }
}
/******************************************************************************/
/*! \Description End message context of a periodic transmission
    \return    void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidEndOfPeriodicMsgExec(
    uint8 u8PeriodicProtArrIdx)
{
  uint8 u8RxBufferId;
  uint8 u8TxBufferId;

  /*! Get RX/TX buffer ID's of the periodic protocol */
  u8RxBufferId = u8RX_BUFFER_ID(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].
      u8PeriodicProtIndex);
  u8TxBufferId = u8TX_BUFFER_ID(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].
      u8PeriodicProtIndex);

  /*! Reset RX/TX buffers indices and unlock them */
  Dsl_astrBufferInfo[u8RxBufferId].udtIndex = (Dcm_MsgLenType)0;
  Dsl_astrBufferInfo[u8RxBufferId].udtStatus = u8ST_BUFF_FREE;
  Dsl_astrBufferInfo[u8TxBufferId].udtIndex = (Dcm_MsgLenType)0;
  Dsl_astrBufferInfo[u8TxBufferId].udtStatus = u8ST_BUFF_FREE;

  /*! Set Periodic protocol state to IDLE */
  Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus =
      u8ST_PERIODIC_PROT_IDLE;
}
#endif

#if(DCM_bROE_ENABLED == STD_ON)
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Queues an Roe response to be transmitted in the main function
    \return      void
    \Trace_To
*******************************************************************************/
/* Dcm607 */
static FUNC(void, DCM_CODE) vidQueueRoeResponse(
    P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC) pudtPduInfo)
{
  uint8   u8Index;
  boolean bQueueOverflow = FALSE;

  /* Dcm605 */
  /*! If the length of the response is less than or equal to the ROE Max Event
   *  Length */
  if(pudtPduInfo->SduLength <= DCM_u16DSP_ROE_MAX_EVENT_LENGTH)
  {
    /*! If the NextEmptyIndex does not equal to the NextFilledIndex, which
     *  means that the queue is not full */
    /*! If the Queue is full */
    if(((Dsl_u16RoeQueRear == (DCM_u16DSP_ROE_MAX_QUEUE_LENGTH-1))
     && (Dsl_u16RoeQueFront == (uint16)0))
     || ((Dsl_u16RoeQueRear+1) == Dsl_u16RoeQueFront))
    {
      /*! Set the overflow flag */
      bQueueOverflow = TRUE;
    }
    /*! Else if the Queue is empty */
    else if(Dsl_u16RoeQueFront == DCM_u16DSP_ROE_MAX_QUEUE_LENGTH)
    {
      /*! Reset both Read and Front indices to 0 */
      Dsl_u16RoeQueRear = (uint16)0;
      Dsl_u16RoeQueFront = (uint16)0;
    }
    /*! Else if the Rear index is at the end of the Queue */
    else if(Dsl_u16RoeQueRear == (DCM_u16DSP_ROE_MAX_QUEUE_LENGTH-1))
    {
      /*! Reset the Rear index to 0 */
      Dsl_u16RoeQueRear = (uint16)0;
    }
    /*! Else */
    else
    {
      /*! Increment the Rear index */
      Dsl_u16RoeQueRear++;
    }

    /*! If no overflow occurred */
    if(bQueueOverflow == FALSE)
    {
      /*! Insert the response at the rear index of the Roe Queue. */
      Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueRear].udtRoeTxPduRef =
          Dsl_strRoeProt.udtRoeTxPduRef;
      Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueRear].udtTxPduInfo.SduLength =
          pudtPduInfo->SduLength;
      Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueRear].udtTxPduInfo.SduDataPtr =
       &Dsl_au8RoeTransQueue[Dsl_u16RoeQueRear*DCM_u16DSP_ROE_MAX_EVENT_LENGTH];
      Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueRear].udtRxPduId =
          Dsl_strRoeProt.udtMsgContext.dcmRxPduId;

      for(u8Index = 0; u8Index < pudtPduInfo->SduLength; u8Index++)
      {
        Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueRear].udtTxPduInfo.
        SduDataPtr[u8Index] = pudtPduInfo->SduDataPtr[u8Index];
      }
    }
  }
}
/******************************************************************************/
/*! \Description Sends a queued Roe response.
    \return      void
    \Trace_To  CDD-0861(0), CDD-0862(0), CDD-0863(0), CDD-0864(0), CDD-1504(0),
               CDD-0868(0)
*******************************************************************************/
/* Dcm607 */
/* !Deviation : Inhibit MISRA rule [4700]: Metric STCYC threshold is violated
 *              for a better readability  */
/* PRQA S 4700 L1 */
static FUNC(void, DCM_CODE) vidSendRoeQuedResponses(void)
{
  PduInfoType    udtPduInfo;
  Std_ReturnType udtPdurTransmitReturn;
  uint8          u8ConnRef;
  uint8          u8RoeProtIdx;
  uint8          u8RoeTransType;
  uint8          u8TxBufferId;
  boolean        bDequeueResponse = FALSE;
  
  /*! Get the connection reference of the main protocol RxPduId */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);
  /*! Get the ROE Protocol Index */
  u8RoeProtIdx = u8ROE_PROT_IDX(Dsl_u8MainProtocolIndex, u8ConnRef);
  /*! Get the ROE Protocol TransType */
  u8RoeTransType = u8PROT_TRANS_TYPE(u8RoeProtIdx);

  /*! If the Roe protocol TransType is TYPE1 while the main protocol is IDLE
   *  OR if the Roe protocol TransType is TYPE2 whatever the status of the main
   *  protocol */
  if(((u8RoeTransType == DCM_PROTOCOL_TYPE1)
    &&(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_IDLE))
    ||(u8RoeTransType == DCM_PROTOCOL_TYPE2))
  {
    /*! If the Roe Queue is not empty and Roe protocol status is IDLE and the
     *  Roe Inter-message timer has expired */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be        */
    /*              implemented during integration phase                  */
    /* PRQA S 3141 ++                                                     */
    /* PRQA S 3138 ++                                                     */
    SchM_Enter_Dcm_Access_057();
    /* PRQA S 3138 --                                                     */
    /* PRQA S 3141 --                                                     */
    if(((Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_IDLE)
      ||(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_PEND_QUE))
    && (Dsl_u16RoeQueFront < DCM_u16DSP_ROE_MAX_QUEUE_LENGTH)
    && (Dsl_u16RoeInterMsgCounter == (uint16)0))
    {
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
      /*              implemented during integration phase              */
      /* PRQA S 3141 ++                                                 */
      /* PRQA S 3138 ++                                                 */
      SchM_Enter_Dcm_Access_058();
      /* PRQA S 3138 --                                                 */
      /* PRQA S 3141 --                                                 */
      /*! If the Roe Transmissions Queue is free */
      if(Dsl_bRoeTransQueStatus == u8ST_BUFF_FREE)
      {
        /*! Lock the Roe Transmissions Queue */
        Dsl_bRoeTransQueStatus = u8ST_BUFF_LOCKED;
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be    */
        /*              implemented during integration phase              */
        /* PRQA S 3141 ++                                                 */
        /* PRQA S 3138 ++                                                 */
        SchM_Exit_Dcm_Access_058();
        /* PRQA S 3138 --                                                 */
        /* PRQA S 3141 --                                                 */
        /*! If there is an Roe response pending to be queued */
        if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_PEND_QUE)
        {
          /*! Get the TX Buffer ID of the Roe protocol */
          u8TxBufferId = u8TX_BUFFER_ID(Dsl_strRoeProt.u8RoeProtIndex);
          /*! Set the SduLength with the Dsl_strRoeProt resDataLen  */
          udtPduInfo.SduLength  = (PduLengthType)Dsl_strRoeProt.udtMsgContext.
              resDataLen;
          /*! Set the SduDataPtr with the TX Buffer Id  */
          udtPduInfo.SduDataPtr =
              Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;
          /*! Call vidQueueRoeResponse() to queue the response */
          vidQueueRoeResponse(
              (P2CONST(PduInfoType,AUTOMATIC,AUTOMATIC))(&udtPduInfo));
          /*! Call vidEndOfRoeMsgExec() */
          vidEndOfRoeMsgExec();
        }
        /*! Get TxPduRef and PduInfo from the Roe Queue at the Front index */
        Dsl_strRoeProt.udtRoeTxPduRef =
            Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueFront].udtRoeTxPduRef;
        Dsl_strRoeProt.udtMsgContext.dcmRxPduId =
            Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueFront].udtRxPduId;
        udtPduInfo.SduLength =
            Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueFront].udtTxPduInfo.SduLength;
        udtPduInfo.SduDataPtr =
            Dsl_audtRoeTransQueueInfo[Dsl_u16RoeQueFront].udtTxPduInfo.SduDataPtr;

        /* Dcm237 */
        Dsl_strRoeProt.u8RoeProtIndex = u8RoeProtIdx;
        /*! Set the Roe Tx In Progress flag. */
        Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_TX_IN_PROGRESS;

        /*! Call PduR_DcmTransmit() to transmit the Roe response */
        udtPdurTransmitReturn = PduR_DcmTransmit(Dsl_strRoeProt.udtRoeTxPduRef,
                                                 &udtPduInfo);
        /*! If PduR_DcmTransmit() does not return E_OK */
        if(udtPdurTransmitReturn != E_OK)
        {
          /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be      */
          /*              implemented during integration phase                */
          /* PRQA S 3141 ++                                                   */
          /* PRQA S 3138 ++                                                   */
          SchM_Exit_Dcm_Access_057();
          /* PRQA S 3138 --                                                   */
          /* PRQA S 3141 --                                                   */
          /*! If Dsl_u8RoeRetryCounter is larger than 0 */
          if(Dsl_u8RoeRetryCounter > 0)
          {
            /*! Decrement Dsl_u8RoeRetryCounter */
            Dsl_u8RoeRetryCounter--;
          }
          /*! If Dsl_u8RoeRetryCounter is 0 */
          if(Dsl_u8RoeRetryCounter == 0)
          {
            /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
            DsdInternal_Confirmation(
                (Dcm_IdContextType)1,
                Dsl_strRoeProt.udtMsgContext.dcmRxPduId,
                NTFRSLT_E_NOT_OK);
            /*! Set Dsl_u8RoeRetryCounter to DCM_u8DSP_ROE_MAX_NUMBER_OF_RETRY
             *  and raise the Dequeue flag */
            bDequeueResponse = TRUE;
            Dsl_u8RoeRetryCounter = DCM_u8DSP_ROE_MAX_NUMBER_OF_RETRY;
          }
        }
        /*! Else if PduR_DcmTransmit() returns E_OK */
        else
        {
          /*! Set the Dequeue flag */
          bDequeueResponse = TRUE;
          /*! Reload Dsl_u16RoeInterMsgCounter with
           *  DCM_u16DSP_ROE_INTER_MESSAGE_TIME */
          Dsl_u16RoeInterMsgCounter = DCM_u16DSP_ROE_INTER_MESSAGE_TIME;
          /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be      */
          /*              implemented during integration phase                */
          /* PRQA S 3141 ++                                                   */
          /* PRQA S 3138 ++                                                   */
          SchM_Exit_Dcm_Access_057();
          /* PRQA S 3138 --                                                   */
          /* PRQA S 3141 --                                                   */
        }

        /*! If the Dequeue flag is set */
        if(bDequeueResponse == TRUE)
        {
          /*! If Front and Rear indices are equal which means the Queue shall be
           *  empty after this transmission */
          if(Dsl_u16RoeQueFront == Dsl_u16RoeQueRear)
          {
            /*! Set both read and front indices with
             *  DCM_u16DSP_ROE_MAX_QUEUE_LENGTH */
            Dsl_u16RoeQueRear = DCM_u16DSP_ROE_MAX_QUEUE_LENGTH;
            Dsl_u16RoeQueFront = DCM_u16DSP_ROE_MAX_QUEUE_LENGTH;
          }
          /*! Else if front index equals DCM_u16DSP_ROE_MAX_QUEUE_LENGTH-1 */
          else if(Dsl_u16RoeQueFront == (DCM_u16DSP_ROE_MAX_QUEUE_LENGTH-1))
          {
            /*! Reset the front index to 0 */
            Dsl_u16RoeQueFront = 0;
          }
          /*! Else */
          else
          {
            /*! Increment the front index. */
            Dsl_u16RoeQueFront++;
          }
        }

        /*! If PduR_DcmTransmit() does not return E_OK */
        if(udtPdurTransmitReturn != E_OK)
        {
          /*! Call vidEndOfRoeMsgExec() */
          vidEndOfRoeMsgExec();
        }

        /*! Unlock the Roe Transmission Queue */
        Dsl_bRoeTransQueStatus = u8ST_BUFF_FREE;
      }
      else
      {
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be      */
        /*              implemented during integration phase                */
        /* PRQA S 3141 ++                                                   */
        /* PRQA S 3138 ++                                                   */
        SchM_Exit_Dcm_Access_057();
        /* PRQA S 3138 --                                                   */
        /* PRQA S 3141 --                                                   */
      }
    }
    else
    {
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be      */
      /*              implemented during integration phase                */
      /* PRQA S 3141 ++                                                   */
      /* PRQA S 3138 ++                                                   */
      SchM_Exit_Dcm_Access_057();
      /* PRQA S 3138 --                                                   */
      /* PRQA S 3141 --                                                   */
    }
  }
}
/* PRQA L:L1 */
#endif
/******************************************************************************/
/*! \Description Handles the Type1 Roe transmission pending on the main protocol
 *               transmission.
    \return      void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidHandleTyp1RoeTx(void)
{
  uint8               u8TxBufferId;
  uint8               u8RxBufferId;
  uint8               u8TransType;
  uint8               u8ConnRef;
  uint8               u8RoeProtIdx;
  Dcm_MsgContextType* pstrRoeMsgContext;

  /*! Get the Connection reference of the main protocol RxPduId */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);

  /*! If the ROE container pointer attached to the main protocol is not Null */
  if(pkstrROE_PTR(Dsl_u8MainProtocolIndex,u8ConnRef) !=
      (Dcm_DslResponseOnEventType*)NULL_PTR)
  {
    /*! Get the Roe protocol index */
    u8RoeProtIdx = u8ROE_PROT_IDX(Dsl_u8MainProtocolIndex, u8ConnRef);
    /*! Get the Roe protocol TransType */
    u8TransType = u8PROT_TRANS_TYPE(u8RoeProtIdx);

    /*! If the Roe TransType is TYPE1 and the Roe protocol status is
     *  PROCESS_PENDING */
    if((u8TransType == DCM_PROTOCOL_TYPE1)
     &&(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_PROCESS_PENDING))
    {
      /*! Get the TX Buffer ID of the main protocol (because it is TYPE1) */
      u8TxBufferId = u8TX_BUFFER_ID(u8RoeProtIdx);
      u8RxBufferId = u8RX_BUFFER_ID(u8RoeProtIdx);
      pstrRoeMsgContext = &Dsl_strRoeProt.udtMsgContext;

      /*! Set Roe context resData with the TX Buffer pointer */
      pstrRoeMsgContext->resData =
          Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;
      /*! Set Dsl_strRoeProt.udtMsgContext.reqData with MsgPtr */
      Dsl_strRoeProt.udtMsgContext.reqData =
          Dcm_kstreDslConfig.astrDcmDslBuffer[u8RxBufferId].pudtBuffer;
      /*! Set the Roe context resMaxDataLen with the TX Buffer size */
      pstrRoeMsgContext->resMaxDataLen =
          Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].udtBufferSize;
      /*! Set the Roe context RxPduId with the main protocol RxPduId */
      pstrRoeMsgContext->dcmRxPduId = Dsl_udtMainProtRxPduId;
      /*! Set the Roe idContext with 1 */
      pstrRoeMsgContext->idContext = (Dcm_IdContextType)1;
      /*! Set the Roe reqType with Rx Addressing Type of the main protocol */
      pstrRoeMsgContext->msgAddInfo.reqType =
       (u8RX_ADDR_TYPE(Dsl_udtMainProtRxPduId) == DCM_PHYS_ADDR) ? FALSE : TRUE;
      /*! Clear the cancelOperation bit of the Roe context */
      pstrRoeMsgContext->msgAddInfo.cancelOperation = FALSE;

      /*! Set the Roe protocol status to PROCESSING */
      Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_PROCESSING;
      /*! Set Dsl_strRoeProt.u8RoeProtIndex with the Roe protocol index */
      Dsl_strRoeProt.u8RoeProtIndex = u8RoeProtIdx;

      /* Dcm195 */
      /*! Lock the Roe TX/RX Buffer */
      Dsl_astrBufferInfo[u8TxBufferId].udtStatus = u8ST_BUFF_LOCKED;
      Dsl_astrBufferInfo[u8RxBufferId].udtStatus = u8ST_BUFF_LOCKED;
      /*! Call DsdInternal_DataIndication() to forward the request to DSD */
      DsdInternal_DataIndication(pstrRoeMsgContext,
                                 u8SID_TABLE(u8RoeProtIdx));
    }
  }
}
/******************************************************************************/
/*! \Description Handles TxConfirmation of Type2 Roe transmission.
    \return      void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidRoeTxConfirmation(
    PduIdType udtDcmTxPduId,
    NotifResultType udtResult)
{
  uint8 u8ConnRef;

  /*! Get the connection reference of the main protocol */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);

  /*! If the passed DcmTxPduId is not of a periodic tx and the Roe container
   *  exists */
  if(pkstrROE_PTR(Dsl_u8MainProtocolIndex,u8ConnRef) !=
      (Dcm_DslResponseOnEventType*)NULL_PTR)
  {
    /*! If the DcmTxPduId equals the Roe TxConfPduId */
    if(udtROE_TX_CONF_PDUID(Dsl_u8MainProtocolIndex,u8ConnRef) == udtDcmTxPduId)
    {
      if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_TX_IN_PROGRESS)
      {
        /*! Call DsdInternal_Confirmation() with Result */
        DsdInternal_Confirmation((Dcm_IdContextType)1,
                                 Dsl_strRoeProt.udtMsgContext.dcmRxPduId,
                                 udtResult);
        /*! Call vidEndOfRoeMsgExec() */
        vidEndOfRoeMsgExec();
      }
      else if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_WAIT_CANCEL_TX)
      {
        /*! Call DsdInternal_Confirmation() with Result */
        DsdInternal_Confirmation((Dcm_IdContextType)1,
                                 Dsl_strRoeProt.udtMsgContext.dcmRxPduId,
                                 NTFRSLT_E_NOT_OK);
        /*! Call vidEndOfRoeMsgExec() */
        vidEndOfRoeMsgExec();
      }
      else
      {
        /*! Do nothing */
      }
    }
  }
}
/******************************************************************************/
/*! \Description Ends the Roe message context.
    \return      void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidEndOfRoeMsgExec(void)
{
  uint8 u8RxBufferId;
  uint8 u8TxBufferId;

  /*! Get RX/TX buffer ID's of the Roe protocol */
  u8RxBufferId = u8RX_BUFFER_ID(Dsl_strRoeProt.u8RoeProtIndex);
  u8TxBufferId = u8TX_BUFFER_ID(Dsl_strRoeProt.u8RoeProtIndex);

  /*! Reset RX/TX buffers indices and unlock them */
  Dsl_astrBufferInfo[u8RxBufferId].udtIndex = (Dcm_MsgLenType)0;
  Dsl_astrBufferInfo[u8RxBufferId].udtStatus = u8ST_BUFF_FREE;
  Dsl_astrBufferInfo[u8TxBufferId].udtIndex = (Dcm_MsgLenType)0;
  Dsl_astrBufferInfo[u8TxBufferId].udtStatus = u8ST_BUFF_FREE;

  /*! Set Roe protocol state to IDLE */
  Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_IDLE;
}
#endif
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Handles Preemption Timeout
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidHandlePreemptTimeout(void)
{
  /*! If Dsl_bPreemptTimeoutOn is true */
  if(Dsl_bPreemptTimeoutOn == TRUE)
  {
    /*! If Dsl_u16PreemptTimeoutCtr is larger than 0 */
    if(Dsl_u16PreemptTimeoutCtr > (uint16)0)
    {
      /*! Decrement Dsl_u16PreemptTimeoutCtr */
      Dsl_u16PreemptTimeoutCtr--;
    }

    /*! If Dsl_u16PreemptTimeoutCtr is 0 */
    if(Dsl_u16PreemptTimeoutCtr == (uint16)0)
    {
      /*! Clear Dsl_bPreemptTimeoutOn */
      Dsl_bPreemptTimeoutOn = FALSE;

      /*! Execute preemption */
      vidExecutePreemption();
    }
  }
}
/******************************************************************************/
/*! \Description Ends the preemption process after cancellation of all running
 *               contexts
*******************************************************************************/
static FUNC(void, DCM_CODE) vidEndPreemptionProcess(void)
{
  /*! If current session is not the default */
  if(Dcm_u8eCurrSesCtrl != DCM_DEFAULT_SESSION)
  {
    /* Dcm168 */
    /*! Call ComM_DCM_InactiveDiagnostic() */
    ComM_DCM_InactiveDiagnostic(u8NETWORK_ID(Dsl_udtMainProtRxPduId));
    /*! Clear Dcm_beDiagnosticsActive */
    Dcm_beDiagnosticsActive = FALSE;
  }

  /*! Set current session to default */
  Dcm_u8eCurrSecLevel = DCM_SEC_LEV_LOCKED;
  /*! Set the current security level to LOCKED */
  Dcm_u8eCurrSesCtrl = DCM_DEFAULT_SESSION;
}
/******************************************************************************/
/*! \Description Returns if all running contexts are Idle or not
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) udtAllContextsIdle(void)
{
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
  uint8          u8PeriodicProtIdx;
#endif
  /*! Set the return flag */
  Std_ReturnType udtAllContextsAreIdle = E_OK;

  /*! If main protocol status is not IDLE */
  if(Dsl_u8MainProtocolStatus != u8ST_MN_PROT_IDLE)
  {
    /*! Clear return flag */
    udtAllContextsAreIdle = E_NOT_OK;
  }
#if(DCM_bROE_ENABLED == STD_ON)
  /*! Else if Roe protocol status is not IDLE */
  else if(Dsl_strRoeProt.udtProtStatus != u8ST_ROE_PROT_IDLE)
  {
    /*! Clear return flag */
    udtAllContextsAreIdle = E_NOT_OK;
  }
#endif
  else
  {
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
    /*! For all periodic transmissions */
    /* !Deviation : Inhibit MISRA rule [2465]: For Loop Only executed once
                    because it is dependent on the configuration              */
    /* PRQA S 2465 ++                                                         */
    for(u8PeriodicProtIdx = 0;
        (u8PeriodicProtIdx < DCM_u8MAX_NUM_PERIODIC_TX)
     && (udtAllContextsAreIdle == E_OK);
        u8PeriodicProtIdx++)
    {
      /* PRQA S 2465 --                                                       */
      /*! If any periodic tx status is not IDLE */
      if(Dsl_astrPeriodicProt[u8PeriodicProtIdx].udtProtStatus !=
          u8ST_PERIODIC_PROT_IDLE)
      {
        /*! Clear return flag */
        udtAllContextsAreIdle = E_NOT_OK;
      }
    }
#endif
  }

  return udtAllContextsAreIdle;
}
#endif
/******************************************************************************/
/*! \Description Monitors Current Session Timeout
    \return void
    \Trace_To  CDD-0876(0), CDD-0878(0), CDD-0879(0), CDD-0904(0),
               CDD-0867(0)
*******************************************************************************/
static FUNC(void, DCM_CODE) vidMonitorCurrSession(void)
{
  /*! If current session is not the default */
  if(Dcm_u8eCurrSesCtrl != DCM_DEFAULT_SESSION)
  {
    /*! If S3 Counter is not zero */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be            */
    /*              implemented during integration phase                      */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_Dcm_Access_052();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */
    if(Dsl_u16S3Counter == (uint16)0)
    {
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be          */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_052();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /* Dcm140 */
      /* Dcm168 */
      /* Dcm139 */
      /*! Call DslInternal_SetSesCtrlType() with default session */
      DslInternal_SetSesCtrlType(DCM_DEFAULT_SESSION);
      /*! Call BswM_Dcm_RequestSessionMode() with default session */
      BswM_Dcm_RequestSessionMode(DCM_DEFAULT_SESSION);
#if((DCM_bROE_ENABLED == STD_ON) && (DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON))
      /*! Clear Roe Transmission Queue. */
      DslInternal_vidClearRoeTxQueue();
#endif
    }
    /*! Else, decrement S3 Counter */
    else
    {
      Dsl_u16S3Counter--;
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be          */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_052();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */
    }
  }
}
/******************************************************************************/
/*! \Description Sends NRC Response Pending
    \return      void
    \Trace_To    CDD-0901(0), CDD-0918(0)
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSendNrcResponsePend(void)
{
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;
  const uint8     LOC_ku8RxBufferId = u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex);

  /*! Clear suppressPosResponse of the Main Protocol Context */
  Dsl_strMainProtMsgContext.msgAddInfo.suppressPosResponse = FALSE; /* Dcm203 */

  udtPduInfo.SduLength = (PduLengthType)3;
  udtPduInfo.SduDataPtr = Dsl_au8InternalTxBuffer;

  /*! Set Dsl_au8InternalTxBuffer[0,1,2] with Response Pending NRC */
  /* Dcm119 */
  Dsl_au8InternalTxBuffer[0] = DspInternal_u8SID_NEG_RESP;
  Dsl_au8InternalTxBuffer[1] =
           Dcm_kstreDslConfig.astrDcmDslBuffer[LOC_ku8RxBufferId].pudtBuffer[0];
  Dsl_au8InternalTxBuffer[2] = DCM_E_RESPONSEPENDING;

  /*! Set Dsl_bIntTxInProgress */
  Dsl_bIntTxInProgress = TRUE;

  /*! Send Negative Response Message */
  udtPdurTransmitReturn =
           PduR_DcmTransmit(udtTX_PDU_REF(Dsl_udtMainProtRxPduId), &udtPduInfo);

  /*! If Transmission fails, clear Dsl_bIntTxInProgress */
  if(udtPdurTransmitReturn != E_OK)
  {
    Dsl_bIntTxInProgress = FALSE;
  }
}
/******************************************************************************/
/*! \Description Returns if NRC Response Pending is allowed for the current
 *               service
    \return      E_OK: NRC is allowed
                 E_NOT_OK: NRC is not allowed
    \Trace_To    CDD-0329(0)
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) udtNrcResponsePendAllowed(void)
{
  uint8          u8RxBufferId;
  uint8          u8CurrentSID;
  boolean        bCurrentProtIsOBD = FALSE;
  Std_ReturnType udtNrcAllowed = E_NOT_OK;

  /*! Get the main protocol RX buffer ID */
  u8RxBufferId = u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex);
  /*! Get the current request Service ID */
  u8CurrentSID =
      Dcm_kstreDslConfig.astrDcmDslBuffer[u8RxBufferId].pudtBuffer[0];

  /*! Set a flag if the current protocol is OBD */
  if( (Dcm_u8eMainProtocolID == DCM_OBD_ON_CAN)
    ||(Dcm_u8eMainProtocolID == DCM_OBD_ON_FLEXRAY)
    ||(Dcm_u8eMainProtocolID == DCM_OBD_ON_IP))
  {
    bCurrentProtIsOBD = TRUE;
  }

  /*! If the current protocol is not OBD or the current Service is 0x04 or
   *  0x09 */
  if(  (bCurrentProtIsOBD == FALSE)
     ||((u8CurrentSID == (uint8)0x04) || (u8CurrentSID == (uint8)0x09))
    )
  {
    /*! Declare that NRC is allowed */
    udtNrcAllowed = E_OK;
  }

  return udtNrcAllowed;
}
/******************************************************************************/
/*! \Description Sends Forced NRC Response Pending
    \return      void
    \Trace_To
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSendForcedNrcResponsePend(void)
{
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;
  const uint8     LOC_ku8RxBufferId = u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex);

  /*! Clear suppressPosResponse of the Main Protocol Context */
  Dsl_strMainProtMsgContext.msgAddInfo.suppressPosResponse = FALSE; /* Dcm203 */

  udtPduInfo.SduLength = (PduLengthType)3;
  udtPduInfo.SduDataPtr = Dsl_au8InternalTxBuffer;

  /*! Set Dsl_au8InternalTxBuffer[0,1,2] with Response Pending NRC */
  /* Dcm119 */
  Dsl_au8InternalTxBuffer[0] = DspInternal_u8SID_NEG_RESP;
  Dsl_au8InternalTxBuffer[1] =
           Dcm_kstreDslConfig.astrDcmDslBuffer[LOC_ku8RxBufferId].pudtBuffer[0];
  Dsl_au8InternalTxBuffer[2] = DCM_E_RESPONSEPENDING;

  /*! Set Dsl_bFrcdRCRRPInProgress */
  Dsl_bFrcdRCRRPInProgress = TRUE;

  /*! Call PduR_DcmTransmit() to send Negative Response Message */
  udtPdurTransmitReturn =
           PduR_DcmTransmit(udtTX_PDU_REF(Dsl_udtMainProtRxPduId), &udtPduInfo);

  /*! If Transmission fails, clear Dsl_bFrcdRCRRPInProgress and call
   *  DspInternal_DcmConfirmation() with DCM_RES_NEG_NOT_OK */
  if(udtPdurTransmitReturn != E_OK)
  {
    Dsl_bFrcdRCRRPInProgress = FALSE;
    DspInternal_DcmConfirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
        Dsl_udtMainProtRxPduId, DCM_RES_NEG_NOT_OK);
  }
}
#if((DCM_bROE_ENABLED == STD_ON) || (DCM_bPERIODIC_TRANS_ENABLED == STD_ON))
/******************************************************************************/
/*! \Description Handles Tx Confirmation when TxConfirmation is called while
 *               main protocol is IDLE
    \return      void
    \Trace_To
*******************************************************************************/
static FUNC(void, DCM_CODE) vidMainIdleTxConfirmation(
    NotifResultType udtResult)
{
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
#if(DCM_bROE_ENABLED == STD_ON)
  const Dcm_IdContextType LOC_kudtPeriodicIdContext = (Dcm_IdContextType)2;
#else
  const Dcm_IdContextType LOC_kudtPeriodicIdContext = (Dcm_IdContextType)1;
#endif
#endif

#if(DCM_bROE_ENABLED == STD_ON)
  /* ISO15765_3-CRS-0503(0) */
  /*! If Roe protocol status is TX_IN_PROGRESS */
  if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_TX_IN_PROGRESS)
  {
    /*! Call DsdInternal_Confirmation() with udtResult */
    DsdInternal_Confirmation((Dcm_IdContextType)1,
                             Dsl_strRoeProt.udtMsgContext.dcmRxPduId,
                             udtResult);
    /*! Set Roe protocol status to IDLE */
    Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_IDLE;
  }
  /*! Else if Roe protocol status is WAIT_CANCEL_TX */
  else if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_WAIT_CANCEL_TX)
  {
    /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
    DsdInternal_Confirmation((Dcm_IdContextType)1,
                             Dsl_strRoeProt.udtMsgContext.dcmRxPduId,
                             NTFRSLT_E_NOT_OK);
    /*! Set Roe protocol status to IDLE */
    Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_IDLE;
  }
  else
  {
    /*! Do nothing */
  }
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
  /* ISO15765_3-CRS-0503(0) */
  if(Dsl_astrPeriodicProt[0].udtProtStatus == u8ST_PERIODIC_PROT_TX_IN_PROGRESS)
  {
    /*! Call DsdInternal_Confirmation() with udtResult */
    DsdInternal_Confirmation(
        LOC_kudtPeriodicIdContext,
        Dsl_astrPeriodicProt[0].udtMsgContext.dcmRxPduId,
        udtResult);
    /*! Call vidEndOfPeriodicMsgExec() */
    vidEndOfPeriodicMsgExec(0);
  }
  else if(Dsl_astrPeriodicProt[0].udtProtStatus == u8ST_PERIODIC_PROT_WAIT_CANCEL_TX)
  {
    /*! Call DsdInternal_Confirmation() with udtResult */
    DsdInternal_Confirmation(
        LOC_kudtPeriodicIdContext,
        Dsl_astrPeriodicProt[0].udtMsgContext.dcmRxPduId,
        NTFRSLT_E_NOT_OK);
    /*! Call vidEndOfPeriodicMsgExec() */
    vidEndOfPeriodicMsgExec(0);
  }
  else
  {
    /*! Do nothing */
  }
#endif
}
#endif
/******************************************************************************/
/*! \Description Handles Tx Confirmation when TxConfirmation is called while
 *               main protocol is TX_PENDING
    \return      void
    \Trace_To
*******************************************************************************/
static FUNC(void, DCM_CODE) vidMainTxPendTxConfirmation(
    PduIdType udtMainProtRxPduId)
{
  uint8           u8TxBufferId;
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;

  /*! Clear IntTxInProgress flag */
  Dsl_bIntTxInProgress = FALSE;

  u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);
  udtPduInfo.SduLength = (PduLengthType)
                                     Dsl_strMainProtMsgContext.resDataLen;
  udtPduInfo.SduDataPtr =
             Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;
  /* Dcm115 */ /* Dcm237 */
  /*! Set main protocol state with TX_IN_PROGRESS */
  Dsl_u8MainProtocolStatus = u8ST_MN_PROT_TX_IN_PROGRESS;
  /*! Call PduR_DcmTransmit() */
  udtPdurTransmitReturn = PduR_DcmTransmit(
                      udtTX_PDU_REF(udtMainProtRxPduId), &udtPduInfo);
  /*! If the transmission fails */
  if(udtPdurTransmitReturn != E_OK)
  {
    /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
    DsdInternal_Confirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                             udtMainProtRxPduId,
                             NTFRSLT_E_NOT_OK);
    /*! End the main context execution */
    vidEndOfMainMsgExec();
  }
}
/******************************************************************************/
/*! \Description Handles Tx Confirmation when TxConfirmation is called while
 *               main protocol is TX_PENDING
    \return      void
    \Trace_To
*******************************************************************************/
static FUNC(void, DCM_CODE) vidMainProcessingTxConfirmation(
    PduIdType udtMainProtRxPduId,
    NotifResultType udtResult)
{
  /*! If Forced RCRRP In Progress is true */
  if(Dsl_bFrcdRCRRPInProgress == TRUE)
  {
    /*! If Result is OK */
    if(udtResult == NTFRSLT_OK)
    {
      /*! Call DspInternal_DcmConfirmation() with DCM_RES_NEG_OK */
      DspInternal_DcmConfirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                                  udtMainProtRxPduId,
                                  DCM_RES_NEG_OK);
    }
    /*! Else if Result is not OK */
    else
    {
      /*! Call DspInternal_DcmConfirmation() with DCM_RES_NEG_NOT_OK */
      DspInternal_DcmConfirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                                  udtMainProtRxPduId,
                                  DCM_RES_NEG_NOT_OK);
    }
    /*! Clear Forced RCRRP In progress flag */
    Dsl_bFrcdRCRRPInProgress = FALSE;
  }
  /*! Clear Dsl_bIntTxInProgress */
  Dsl_bIntTxInProgress = FALSE;
}
/******************************************************************************/
/*! \Description Handles TxConfirmation of main protocol
    \return      void
*******************************************************************************/
/* !Deviation : Inhibit MISRA rule [4700]: Metric STSUB threshold is violated
 *              for a better readability  */
/* PRQA S 4700 L1 */
static FUNC(void, DCM_CODE) vidMainTxConfirmation(
    NotifResultType udtResult)
{
  /* Dcm624 */
  switch(Dsl_u8MainProtocolStatus)
  {
  #if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  /*! If main state is TX BOOT LOADER IN PROGRESS */
  case u8ST_MN_PROT_TX_BT_LDR_IN_PROGRESS:
    /*! End boot loader process */
    vidEndOfBootloaderExec();
    break;
  #endif

  /*! Else if main state is Tx In Progress */
  case u8ST_MN_PROT_TX_IN_PROGRESS: /* Case of Main Request TxConf */
    /* Dcm117 */ /* Dcm235 */
    /*! Call DsdInternal_Confirmation() */
    DsdInternal_Confirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                             Dsl_udtMainProtRxPduId, udtResult);
    /* Dcm141 */
    /* Dcm164 */
    /* Dcm352, Dcm353 */
    /*! End main process */
    vidEndOfMainMsgExec();
    break;
  /*! Else if main state is TX CNC in progress */
  case u8ST_MN_PROT_TX_CNC_IN_PROGRESS:
    /* Dcm141 */
    /* Dcm164 */
    /* Dcm352, Dcm353 */
    /*! End main process */
    vidEndOfMainMsgExec();
    break;
  /*! Else if main state is Processing */
  case u8ST_MN_PROT_PROCESSING: /* Case of Internal TxConf */ /* Dcm165 */
    /*! Call vidMainProcessingTxConfirmation() */
    vidMainProcessingTxConfirmation(Dsl_udtMainProtRxPduId, udtResult);
    break;
  /*! Else if main state is TX GR In Progress */
  case u8ST_MN_PROT_TX_GR_IN_PROGRESS:
    /* Dcm352, Dcm353 */
    /*! End main process */
    vidEndOfMainMsgExec();
    break;
  /*! Else if main state is TX Pending */
  case u8ST_MN_PROT_TX_PENDING: /* Case of Internal TxConf & Process Done */
    vidMainTxPendTxConfirmation(Dsl_udtMainProtRxPduId);
    break;
  /*! Else if main protocol status is GR_TX_PENDING */
  case u8ST_MN_PROT_GR_TX_PENDING:
    /*! Set the main protocol status to SEND_GR */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_SEND_GR;
    break;
  /*! Else if main protocol status is WAIT_TO_END_PRCS */
  case u8ST_MN_PROT_WAIT_TO_END_PRCS:
    /*! Call vidEndOfMainMsgExec() */
    vidEndOfMainMsgExec();
    break;
  case u8ST_MN_PROT_WAIT_CANCEL_INT_TX:
    /*! If this is a TxConf of a CancelTx operation of an internal TX */
    /*! End main process */
    vidEndOfMainMsgExec();
    break;
  case u8ST_MN_PROT_WAIT_CANCEL_TX:
    /*! If this is a TxConf of a CancelTx operation of main response TX */
    /* Dcm461 */
    /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
    DsdInternal_Confirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                             Dsl_udtMainProtRxPduId,
                             NTFRSLT_E_NOT_OK);
    /*! End main process */
    vidEndOfMainMsgExec();
    break;

    /*! IF Paged Buffering is enabled */
  #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    /*! If main protocol status is PAGE_DATA_PROCESSED */
  case u8ST_MN_PROT_PAGE_DATA_PROCESSED:
    /* Dcm235 */
    /*! Call DsdInternal_Confirmation() */
    DsdInternal_Confirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                             Dsl_udtMainProtRxPduId, udtResult);
    /*! End main process */
    vidEndOfMainMsgExec();
    break;
    /*! If main protocol status is PAGE_TX_PENDING */
  case u8ST_MN_PROT_PAGE_TX_PENDING:
    /*! Clear Dsl_bIntTxInProgress */
    Dsl_bIntTxInProgress = FALSE;
    /*! Set main protocol status to PAGE_DATA_PROCESSED */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_PAGE_DATA_PROCESSED;
    break;
  #endif

#if((DCM_bROE_ENABLED == STD_ON) || (DCM_bPERIODIC_TRANS_ENABLED == STD_ON))
    /*! If main protocol status is IDLE */
  case u8ST_MN_PROT_IDLE:
    /*! Call vidMainIdleTxConfirmation() */
    vidMainIdleTxConfirmation(udtResult);
    break;
#endif

  default:
    break;
  }
}
/* PRQA L:L1 */
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
/******************************************************************************/
/*! \Description Sends Bootloader Response \n
    \return      void \n
    \Trace_To CDD-DSL-0076(0)
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSendBootloaderResponse(void)
{
  uint8           u8ProtocolIdx;
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;
  uint8           u8TxBufferId;
  uint8           u8RxBufferId;
  uint8           u8SesIndex;
  boolean         bSesFound = FALSE;
  uint16          u16P2ReloadValue = 0;
  uint16          u16P2StarReloadValue = 0;
  uint16          u16P2InMs;
  uint16          u16P2StarInMs;
  P2CONST(Dcm_DspSessionType,AUTOMATIC,DCM_CFG_CONST)
                  LOC_pkstrDspSessTableIdRef;

  u8ProtocolIdx = u8RX_PROTOCOL_IDX(Dsl_strProgConditions.udtPduId);
  u8TxBufferId  = u8TX_BUFFER_ID(u8ProtocolIdx);
  u8RxBufferId  = u8RX_BUFFER_ID(u8ProtocolIdx);

  udtPduInfo.SduDataPtr =
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;

  Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[1] =
      (Dcm_MsgItemType)(Dsl_strProgConditions.SubFncId & 0x7F);

  /*! If Prog Conditions Sid is DSC */
  if(Dsl_strProgConditions.Sid == u8DSC_SID)
  {
    /*! Lock the Tx & Rx Buffers */
    Dsl_astrBufferInfo[u8TxBufferId].udtStatus = u8ST_BUFF_LOCKED;
    Dsl_astrBufferInfo[u8RxBufferId].udtStatus = u8ST_BUFF_LOCKED;

    /*! Set first byte of Tx buffer with 0x50 */
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[0] = 0x50;

    LOC_pkstrDspSessTableIdRef = Dcm_kstreDslConfig.
          astrDcmDslProtocolRow[u8ProtocolIdx].pkstrDcmDslProtocolSessionRef;

    /*! Search for the default session in the Prog Conditions Sid */
    for(u8SesIndex = 0;(u8SesIndex < LOC_pkstrDspSessTableIdRef->u8NumOfSessRows)
    && (bSesFound == FALSE); u8SesIndex++)
    {
      /*! If found, save P2 & P2Star timings */
      if(LOC_pkstrDspSessTableIdRef->ppkstrDcmDspSessionRowType[u8SesIndex]->
          u8DcmDspSessionLevel == DCM_DEFAULT_SESSION)
      {
        bSesFound = TRUE;

        u16P2ReloadValue = LOC_pkstrDspSessTableIdRef->
            ppkstrDcmDspSessionRowType[u8SesIndex]->
            u16DcmDspSessionP2ServerMax;

        u16P2StarReloadValue = LOC_pkstrDspSessTableIdRef->
            ppkstrDcmDspSessionRowType[u8SesIndex]->
            u16DcmDspSessionP2StarServerMax;
      }
    }

    /*! Fill the Tx buffer with the response data */
    u16P2InMs = (uint16)(u16P2ReloadValue * DCM_TASK_TIME_IN_MS);
#if(DCM_bPSA_SPECIFIC_CONF == STD_ON)
    u16P2StarInMs = (uint16)((uint16)(u16P2StarReloadValue * 
                                      DCM_TASK_TIME_IN_MS)/(uint16)10);
#else
    u16P2StarInMs = (uint16)(u16P2StarReloadValue * DCM_TASK_TIME_IN_MS);
#endif
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[2] =
        (uint8)((u16P2InMs & 0xFF00)>>8);
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[3] =
        (uint8)(u16P2InMs & 0x00FF);
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[4] =
        (uint8)((u16P2StarInMs & 0xFF00)>>8);
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[5] =
        (uint8)(u16P2StarInMs & 0x00FF);
    udtPduInfo.SduLength = (PduLengthType)6;

    Dsl_strMainProtMsgContext.resDataLen = (Dcm_MsgLenType)6;

    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_TX_BT_LDR_IN_PROGRESS;

    /*! Transmit the response */
    udtPdurTransmitReturn = PduR_DcmTransmit(
                                  udtTX_PDU_REF(Dsl_strProgConditions.udtPduId),
                                  &udtPduInfo);
    /*! If Transmission fails, call vidEndOfBootloaderExec() */
    if(udtPdurTransmitReturn != E_OK)
    {
      vidEndOfBootloaderExec();
    }
  }
  /*! Else if Sid is ECU_RESET */
  else if(Dsl_strProgConditions.Sid == u8ECU_RESET_SID)
  {
    /*! Lock the Tx & Rx buffers */
    Dsl_astrBufferInfo[u8TxBufferId].udtStatus = u8ST_BUFF_LOCKED;
    Dsl_astrBufferInfo[u8RxBufferId].udtStatus = u8ST_BUFF_LOCKED;

    /*! Fill the Tx buffer with the response data */
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[0] = 0x51;

    if(Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[1] == 0x04)
    {
      Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[2] =
          Dcm_kstreDspConfig.u8DcmDspPowerDownTime;
      udtPduInfo.SduLength = (PduLengthType)3;

      Dsl_strMainProtMsgContext.resDataLen = (Dcm_MsgLenType)3;
    }
    else
    {
      udtPduInfo.SduLength = (PduLengthType)2;

      Dsl_strMainProtMsgContext.resDataLen = (Dcm_MsgLenType)2;
    }

    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_TX_BT_LDR_IN_PROGRESS;

    /*! Transmit the response data */
    udtPdurTransmitReturn = PduR_DcmTransmit(
                                  udtTX_PDU_REF(Dsl_strProgConditions.udtPduId),
                                  &udtPduInfo);
    /*! If Transmission fails, call vidEndOfBootloaderExec() */
    if(udtPdurTransmitReturn != E_OK)
    {
      vidEndOfBootloaderExec();
    }
  }
  /*! Call vidEndOfBootloaderExec() */
  else
  {
    vidEndOfBootloaderExec();
  }
}
#endif
/******************************************************************************/
/*! \Description Sends General Reject NRC
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSendGeneralReject(void)
{
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;
  const uint8     LOC_ku8RxBufferId = u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex);

  udtPduInfo.SduLength = (PduLengthType)3;
  udtPduInfo.SduDataPtr = Dsl_au8InternalTxBuffer;

  /*! Fill the Internal Tx Buffer with NRC General Reject */
  Dsl_au8InternalTxBuffer[0] = DspInternal_u8SID_NEG_RESP;
  Dsl_au8InternalTxBuffer[1] =
      Dcm_kstreDslConfig.astrDcmDslBuffer[LOC_ku8RxBufferId].pudtBuffer[0];
  Dsl_au8InternalTxBuffer[2] = DCM_E_GENERALREJECT;

  Dsl_u8MainProtocolStatus = u8ST_MN_PROT_TX_GR_IN_PROGRESS;

  /*! Send General Reject Message */
  udtPdurTransmitReturn = PduR_DcmTransmit(
                            udtTX_PDU_REF(Dsl_udtMainProtRxPduId), &udtPduInfo);

  /*! If Transmission fails */
  if(udtPdurTransmitReturn != E_OK)
  {
    /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
    DsdInternal_Confirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                             Dsl_udtMainProtRxPduId,
                             NTFRSLT_E_NOT_OK);
    /*! End main context execution */
    vidEndOfMainMsgExec();
  }
}
/******************************************************************************/
/*! \Description Returns if NRC General Reject is allowed for the current
 *               service
    \return E_OK: NRC is allowed
            E_NOT_OK: NRC is not allowed
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) udtNrcGeneralRejectAllowed(void)
{
  Std_ReturnType udtNrcAllowed = E_OK;

  /*! If the current protocol is OBD */
  if((Dcm_u8eMainProtocolID == DCM_OBD_ON_CAN)
   ||(Dcm_u8eMainProtocolID == DCM_OBD_ON_FLEXRAY)
   ||(Dcm_u8eMainProtocolID == DCM_OBD_ON_IP))
  {
    /*! Declare that NRC is not allowed */
    udtNrcAllowed = E_NOT_OK;
  }

  return udtNrcAllowed;
}
/******************************************************************************/
/*! \Description Sends Busy Responses
    \return      void
    \Trace_To    CDD-0824(0), CDD-0825(0), CDD-0878(0), CDD-0879(0)
*******************************************************************************/
/* !Deviation : Inhibit MISRA rule [4700]: Metric STSUB threshold is violated
 *              for a better readability  */
/* PRQA S 4700 L1 */
static FUNC(void, DCM_CODE) vidHandleBusyResponses(void)
{
  /*! If P2Counter is larger than P2Adjust*/
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented  */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Enter_Dcm_Access_051();
  /* PRQA S 3138 --                                                           */
  /* PRQA S 3141 --                                                           */

  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_056();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */
  if(Dsl_u16P2Counter > Dsl_u16P2Adjust)
  {
    /*! Decrement P2Counter */
    Dsl_u16P2Counter--;
  }
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Exit_Dcm_Access_056();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */

  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented  */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Exit_Dcm_Access_051();
  /* PRQA S 3138 --                                                           */
  /* PRQA S 3141 --                                                           */

  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented  */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Enter_Dcm_Access_051();
  /* PRQA S 3138 --                                                           */
  /* PRQA S 3141 --                                                           */

  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_056();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */

  /*! If P2Counter equals P2Adjust */
  if(Dsl_u16P2Counter == Dsl_u16P2Adjust)
  {
    /*! If Max Number of RespPend is not 0xFF and the number of sent RespPend is
     *  less than the maximum configured, increment RespPendCount */
    if((Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslDiagRespMaxNumRespPend !=
        (uint8)0xFF)
      &&(Dsl_u8RespPendCount <
         Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslDiagRespMaxNumRespPend))
    {
      Dsl_u8RespPendCount++;
    }

    /*! If ReponsePendCount is less than the configured Max, or Max is 0xFF or
     *  there is a cancellation in progress */
    if((Dsl_u8RespPendCount <
        Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslDiagRespMaxNumRespPend)
     ||(Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslDiagRespMaxNumRespPend ==
        (uint8)0xFF)
     || (Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation == TRUE))
    {
      /*! Reload P2Counter & P2Adjust */
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Enter_Dcm_Access_055();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */
      Dsl_u16P2Counter = Dsl_u16P2StarReload;
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_055();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      Dsl_u16P2Adjust = u16P2STAR_SERVER_ADJUST(Dsl_u8MainProtocolIndex);

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_056();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be   */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_051();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /*! If no Internal TX In Progress and Response Pending NRC is allowed for
       *  the current service */
      /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used in
       *              conditional statement for better readability            */
      /* PRQA S 3415 ++                                                       */
      /* PRQA S 3416 ++                                                       */
      if((Dsl_bIntTxInProgress == FALSE)
       &&(Dsl_bFrcdRCRRPInProgress == FALSE)
       &&(udtNrcResponsePendAllowed() == E_OK))
      {
        /* PRQA S 3415 --                                                     */
        /* PRQA S 3416 --                                                     */
        /* Dcm165 */
        /*! Call vidSendNrcResponsePend() */
        vidSendNrcResponsePend();
      }
    }
    /*! Else */
    /* Dcm120 */
    else
    {
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_056();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /*! If Int Tx In Progress is False*/
      if(Dsl_bIntTxInProgress == FALSE)
      {
        /*! Set Cancel Bit of Main Prot Context*/
        Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation = TRUE;
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Enter_Dcm_Access_055();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */
        /*! Reload the P2Counter with P2Star value */
        Dsl_u16P2Counter = Dsl_u16P2StarReload;
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_Dcm_Access_055();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */
        /*! Reload the P2Adjust */
        Dsl_u16P2Adjust = u16P2STAR_SERVER_ADJUST(Dsl_u8MainProtocolIndex);

        /*! If no Internal TX In Progress and Response Pending NRC is allowed for
         *  the current service */
        /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used in
         *              conditional statement for better readability            */
        /* PRQA S 3415 ++                                                       */
        /* PRQA S 3416 ++                                                       */
        if((Dsl_bFrcdRCRRPInProgress == FALSE)
         &&(udtNrcResponsePendAllowed() == E_OK))
        {
          /* PRQA S 3415 --                                                     */
          /* PRQA S 3416 --                                                     */
          /* Dcm165 */
          /*! Call vidSendNrcResponsePend() */
          vidSendNrcResponsePend();
        }

        /*! If General Reject NRC is allowed for the current service */
        /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used
         *              conditional statement for better readability          */
        /* PRQA S 3415 ++                                                     */
        /* PRQA S 3416 ++                                                     */
        if(udtNrcGeneralRejectAllowed() == E_OK)
        {
          /* PRQA S 3415 --                                                   */
          /* PRQA S 3416 --                                                   */
          /*! Set Dsl_bGeneralRejectPend */
          Dsl_bGeneralRejectPend = TRUE;
        }
      }
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be   */
      /*              implemented during integration phase                  */
      /* PRQA S 3141 ++                                                     */
      /* PRQA S 3138 ++                                                     */
      SchM_Exit_Dcm_Access_051();
      /* PRQA S 3138 --                                                     */
      /* PRQA S 3141 --                                                     */
    }
  }
  else
  {
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_056();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */

    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_051();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */
  }
}
/* PRQA L:L1 */
/******************************************************************************/
/*! \Description Sends NRC CNC \n
 *  \param[in] u8ProtocolIdx Protocol Index \n
 *  \Range     0..255 \n
 *  \param[in] udtRxPduId Rx PduId \n
 *  \Range     0..65535 \n
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSendNrcCondNotCorr(uint8 u8ProtocolIdx,
                                                  PduIdType udtRxPduId)
{
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;
  uint8           u8TxBufferId;
  uint8           u8RxBufferId;

  u8TxBufferId = u8TX_BUFFER_ID(u8ProtocolIdx);
  u8RxBufferId = u8RX_BUFFER_ID(u8ProtocolIdx);

  udtPduInfo.SduLength = (PduLengthType)3;
  udtPduInfo.SduDataPtr =
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;

  /*! Fill the Tx Buffer with NRC data */
  Dsl_astrBufferInfo[u8TxBufferId].udtIndex = (Dcm_MsgLenType)0;
  Dsl_strMainProtMsgContext.resDataLen = (Dcm_MsgLenType)3;

  Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[0] =
    DspInternal_u8SID_NEG_RESP;

  Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[1] =
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8RxBufferId].pudtBuffer[0];

  Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[2] =
    DCM_E_CONDITIONSNOTCORRECT;

#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
  /*! If RxPduId is of Main Msg */
  if(udtRxPduId == Dsl_udtMainProtRxPduId)
  {
#endif
    /*! Set main state to u8ST_MN_PROT_TX_CNC_IN_PROGRESS */
    Dsl_u8MainProtocolStatus = u8ST_MN_PROT_TX_CNC_IN_PROGRESS;

    /*! Activate Diagnostics */
    ComM_DCM_ActiveDiagnostic(u8NETWORK_ID(Dsl_udtMainProtRxPduId));
    Dcm_beDiagnosticsActive = TRUE;
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
  }
  /*! Else */
  else
  {
    /*! Set preemption state to u8ST_PREEMPT_PROT_TX_CNC_IN_PROGRESS */
    Dsl_u8PreemptProtStatus = u8ST_PREEMPT_PROT_TX_CNC_IN_PROGRESS;
    /*! Activate Diagnostics */
    ComM_DCM_ActiveDiagnostic(u8NETWORK_ID(Dsl_udtPreemptRxPduId));
  }
#endif

  /*! Transmit the NRC */
  udtPdurTransmitReturn = PduR_DcmTransmit(udtTX_PDU_REF(udtRxPduId),
                                           &udtPduInfo);

  /*! If Transmission fails, end process */
  if(udtPdurTransmitReturn != E_OK)
  {
    if(udtRxPduId == Dsl_udtMainProtRxPduId)
    {
      /*! Call DsdInternal_Confirmation() with NTFRSLT_E_NOT_OK */
      DsdInternal_Confirmation(DspInternal_u8DSL_MAIN_PROT_CONTEXT,
                               Dsl_udtMainProtRxPduId,
                               NTFRSLT_E_NOT_OK);
      /*! End the main context execution */
      vidEndOfMainMsgExec();
    }
    else
    {
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
      /*! End preemption context execution */
      vidEndOfPreemptMsgExec();
#endif
    }
  }
}
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Sends NRC Busy Repeat Request
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidSendNrcBusyRepeatReq(void)
{
  PduInfoType     udtPduInfo;
  PduR_ReturnType udtPdurTransmitReturn;
  uint8           u8TxBufferId;
  uint8           u8RxBufferId;

  u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8PreemptProtocolIndex);
  u8RxBufferId = u8RX_BUFFER_ID(Dsl_u8PreemptProtocolIndex);

  /*! Fill the TX buffer with the NRC data */
  udtPduInfo.SduLength = (PduLengthType)3;
  udtPduInfo.SduDataPtr =
      Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer;

  Dsl_astrBufferInfo[u8TxBufferId].udtIndex = (Dcm_MsgLenType)0;

  Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[0] =
      DspInternal_u8SID_NEG_RESP;

  Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[1] =
    Dcm_kstreDslConfig.astrDcmDslBuffer[u8RxBufferId].pudtBuffer[0];

  Dcm_kstreDslConfig.astrDcmDslBuffer[u8TxBufferId].pudtBuffer[2] =
      DCM_E_BUSYREPEATREQUEST;

  /*! Set preemption state to TX_IN_PROGRESS */
  Dsl_u8PreemptProtStatus = u8ST_PREEMPT_PROT_TX_IN_PROGRESS;

  ComM_DCM_ActiveDiagnostic(u8NETWORK_ID(Dsl_udtPreemptRxPduId));

  /*! Transmit the NRC */
  udtPdurTransmitReturn = PduR_DcmTransmit(udtTX_PDU_REF(Dsl_udtPreemptRxPduId),
                                           &udtPduInfo);

  /*! If Transmission fails, end preemption process */
  if(udtPdurTransmitReturn != E_OK)
  {
    vidEndOfPreemptMsgExec();
  }
}
#endif
/******************************************************************************/
/*! \Description Prepares Main Protocol Message Context before forwarding to
 *               DSD
    \return      void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidPrepMnProtMsgContext(void)
{
  const uint8 LOC_ku8RxBufferId = u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex);
  const uint8 LOC_ku8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);

  Dsl_strMainProtMsgContext.reqData       =
      Dcm_kstreDslConfig.astrDcmDslBuffer[LOC_ku8RxBufferId].pudtBuffer;
  Dsl_strMainProtMsgContext.reqDataLen    =
      Dsl_astrBufferInfo[LOC_ku8RxBufferId].udtIndex;
  /*! Lock the Tx and Rx buffers */
  Dsl_astrBufferInfo[LOC_ku8RxBufferId].udtStatus = u8ST_BUFF_LOCKED;
  Dsl_astrBufferInfo[LOC_ku8TxBufferId].udtStatus = u8ST_BUFF_LOCKED;

  /*! Prepare the Main Message Context */
  Dsl_strMainProtMsgContext.resData       =
      Dcm_kstreDslConfig.astrDcmDslBuffer[LOC_ku8TxBufferId].pudtBuffer;
  Dsl_strMainProtMsgContext.resMaxDataLen =
      Dcm_kstreDslConfig.astrDcmDslBuffer[LOC_ku8TxBufferId].udtBufferSize;

  Dsl_strMainProtMsgContext.dcmRxPduId    = Dsl_udtMainProtRxPduId;
  Dsl_strMainProtMsgContext.idContext     = DspInternal_u8DSL_MAIN_PROT_CONTEXT;
  Dsl_strMainProtMsgContext.msgAddInfo.reqType = 
    (u8RX_ADDR_TYPE(Dsl_udtMainProtRxPduId) == DCM_PHYS_ADDR) ? FALSE : TRUE;

  /*! Clear cancel bit */
  Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation = FALSE;
}
/******************************************************************************/
/*! \Description Starts Protocol in Application \n
 *  \param[in] u8ProtocolIdx Protocol Index \n
 *  \Range     0..255 \n
    \return Starting Success/Failure flag.
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) u8StartProtocol(uint8 u8ProtocolIdx)
{
  uint8 u8LoopIdx;
  uint8 u8Return = E_OK;

  /*! Loop for all Callback Request Services */
  /* !Deviation : Inhibit MISRA rule [2465]: For Loop Only executed once 
                  because it is dependent on the configuration                */
  /* PRQA S 2465 ++                                                           */
  for(u8LoopIdx = (uint8)0; 
      (u8LoopIdx < DCM_u8NUM_OF_CALLBACK_REQ_SERV) && (u8Return == E_OK);
      u8LoopIdx++)
  {
    /* PRQA S 2465 --                                                         */
    /*! If service pointer is not NULL, call Xxx_StartProtocol() */
    if(Dcm_kstreDslConfig.astrCbkDcmRequstService[u8LoopIdx].
      pfu8StartProtocol != NULL_PTR)
    {
      u8Return = (*Dcm_kstreDslConfig.astrCbkDcmRequstService[u8LoopIdx].
        pfu8StartProtocol)(u8PROTOCOL_ID(u8ProtocolIdx));
    }
  }

  return (u8Return);
}
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Stops Protocol in Application \n
 *  \param[in] u8ProtocolIdx Protocol Index \n
 *  \Range     0..255 \n
    \return Stopping Success/Failure flag.
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) u8StopProtocol(uint8 u8ProtocolIdx)
{
  uint8 u8LoopIdx;
  uint8 u8Return = E_OK;

  /*! Loop for all Callback Request Services */
  /* !Deviation : Inhibit MISRA rule [2465]: For Loop Only executed once 
                  because it is dependent on the configuration                */
  /* PRQA S 2465 ++                                                           */
  for(u8LoopIdx = (uint8)0; 
     (u8LoopIdx < DCM_u8NUM_OF_CALLBACK_REQ_SERV) && (u8Return == E_OK);
      u8LoopIdx++)
  {
    /* PRQA S 2465 --                                                         */
    /*! If service pointer is not NULL, call Xxx_StopProtocol() */
    if(Dcm_kstreDslConfig.astrCbkDcmRequstService[u8LoopIdx].
      pfu8StopProtocol != NULL_PTR)
    {
      u8Return = (*Dcm_kstreDslConfig.astrCbkDcmRequstService[u8LoopIdx].
        pfu8StopProtocol)(u8PROTOCOL_ID(u8ProtocolIdx));
    }
  }

  return (u8Return);
}
#endif
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
/******************************************************************************/
/*! \Description End of bootloader process execution
    \return      void
    \Trace_To
*******************************************************************************/
static FUNC(void, DCM_CODE) vidEndOfBootloaderExec(void)
{
  uint8 u8RxBufferId;
  uint8 u8TxBufferId;
  uint8 u8ProtocolIdx;

  u8ProtocolIdx = u8RX_PROTOCOL_IDX(Dsl_strProgConditions.udtPduId);
  u8RxBufferId  = u8RX_BUFFER_ID(u8ProtocolIdx);
  u8TxBufferId  = u8TX_BUFFER_ID(u8ProtocolIdx);

  /*! Reset Rx buffer index */
  Dsl_astrBufferInfo[u8RxBufferId].udtIndex = (Dcm_MsgLenType)0;
  /*! Unlock the Rx buffer */
  Dsl_astrBufferInfo[u8RxBufferId].udtStatus = u8ST_BUFF_FREE;

  /*! Reset Tx buffer index */
  Dsl_astrBufferInfo[u8TxBufferId].udtIndex = (Dcm_MsgLenType)0;
  /*! Unlock the Tx buffer */
  Dsl_astrBufferInfo[u8TxBufferId].udtStatus = u8ST_BUFF_FREE;

  /*! Set main state to IDLE */
  Dsl_u8MainProtocolStatus = u8ST_MN_PROT_IDLE;
}
#endif
/******************************************************************************/
/*! \Description End of main msg process execution
    \return      void
    \Trace_To    CDD-0906(0), CDD-1558(0)
*******************************************************************************/
static FUNC(void, DCM_CODE) vidEndOfMainMsgExec(void)
{
  NetworkHandleType udtNetworkId;
  uint8             u8RxBufferId;
  uint8             u8TxBufferId;

  udtNetworkId = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                 pkstrDcmDslProtocolRx[Dsl_udtMainProtRxPduId].
                 u8DcmDslProtocolRxChannelId;

  /*! Get RX/TX buffer ID's of the main protocols */
  u8RxBufferId = u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex);
  u8TxBufferId = u8TX_BUFFER_ID(Dsl_u8MainProtocolIndex);

  /*! Reset Dsl_u8RespPendCount to 0 */
  Dsl_u8RespPendCount = (uint8)0;

  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_051();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */

  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_054();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */
  /*! Set P2 Counter to its reload value */
  Dsl_u16P2Counter = Dsl_u16P2Reload;
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Exit_Dcm_Access_054();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */

  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Exit_Dcm_Access_051();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */

  /* Dcm170 */
  /*! If Current Session is default */
  if(Dcm_u8eCurrSesCtrl == DCM_DEFAULT_SESSION)
  {
    /*! If message is not "Tester Present with suppressed response" or
     *  Addressing type is functional */
    if((bMSG_TP_AND_RESP_SUPP(u8RX_BUFFER_ID(Dsl_u8MainProtocolIndex)) != TRUE)
     ||(u8RX_ADDR_TYPE(Dsl_udtMainProtRxPduId) != DCM_FUNC_ADDR))
    {
      /* Dcm166, Dcm697 */
      /*! Inactivate Diagnostices */
      ComM_DCM_InactiveDiagnostic(udtNetworkId);
      Dcm_beDiagnosticsActive = FALSE;
    }
  }
  /*! Else, reload S3 Counter */
  else
  {
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_Dcm_Access_052();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */

    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_Dcm_Access_053();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */
    Dsl_u16S3Counter = Dsl_u16S3Reload;
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_053();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */

    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_052();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */
  }

  /*! Reset Rx/Tx buffers indices and unlock them */
  Dsl_astrBufferInfo[u8RxBufferId].udtIndex = (Dcm_MsgLenType)0;
  Dsl_astrBufferInfo[u8RxBufferId].udtStatus = u8ST_BUFF_FREE;

  Dsl_astrBufferInfo[u8TxBufferId].udtIndex = (Dcm_MsgLenType)0;
  Dsl_astrBufferInfo[u8TxBufferId].udtStatus = u8ST_BUFF_FREE;

#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
  /*! Clear PreemptionTimeoutOn flag */
  Dsl_bPreemptTimeoutOn = FALSE;
#endif

  /*! Clear Internal TX flag */
  Dsl_bIntTxInProgress = FALSE;
  /*! Clear Forced RCRRP TX flag */
  Dsl_bFrcdRCRRPInProgress = FALSE;
  /*! Clear GR Response Pending flag */
  Dsl_bGeneralRejectPend = FALSE;

  /*! Set main state to IDLE */
  Dsl_u8MainProtocolStatus = u8ST_MN_PROT_IDLE;
}
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description End of Preemting message process execution
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidEndOfPreemptMsgExec(void)
{
  /*! Inactivate Diagnostics */
  ComM_DCM_InactiveDiagnostic(u8NETWORK_ID(Dsl_udtPreemptRxPduId));
  /*! Set preemption state to IDLE */
  Dsl_u8PreemptProtStatus = u8ST_PREEMPT_PROT_IDLE;
}
#endif
/******************************************************************************/
/*! \Description Reloads session timers \n
 *  \param[in] u8ProtocolIdx Protocol Index \n
 *  \Range     0..255 \n
 *  \param[in] udtSesCtrlType Session Control Type \n
 *  \Range     0..255 \n
    \return void
*******************************************************************************/
static FUNC(void, DCM_CODE) vidReloadSessionTimers(uint8 u8ProtocolIdx, 
                                                 Dcm_SesCtrlType udtSesCtrlType)
{
  CONSTP2CONST(Dcm_DspSessionType, AUTOMATIC, DCM_APPL_CONST)
              LOC_kpkstrDspSessTableIdRef = pkstrSESSION_REF(u8ProtocolIdx);
  uint8       u8SesIndex;
  boolean     bSesFound = FALSE;
  
  /*! If Session is not default */
  if(udtSesCtrlType != DCM_DEFAULT_SESSION)
  {
    /*! Reload S3 Counter */
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_Dcm_Access_053();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */
    Dsl_u16S3Reload  = u16S3_COUNT;

    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_Dcm_Access_052();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */
    Dsl_u16S3Counter = Dsl_u16S3Reload;
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_052();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */

    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_053();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */
  }

  /*! Search for the session in the session row */
  for(u8SesIndex = (uint8)0;
     (u8SesIndex < LOC_kpkstrDspSessTableIdRef->u8NumOfSessRows)
   &&(bSesFound == FALSE);
     u8SesIndex++)
  {
    /*! If found, load its P2/P2Star/P2Adjust timers */
    if(LOC_kpkstrDspSessTableIdRef->ppkstrDcmDspSessionRowType[u8SesIndex]->
        u8DcmDspSessionLevel == udtSesCtrlType)
    {
      bSesFound = TRUE;

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Enter_Dcm_Access_054();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */
      Dsl_u16P2Reload = LOC_kpkstrDspSessTableIdRef->
                        ppkstrDcmDspSessionRowType[u8SesIndex]->
                        u16DcmDspSessionP2ServerMax;
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_054();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Enter_Dcm_Access_055();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */
      Dsl_u16P2StarReload = LOC_kpkstrDspSessTableIdRef->
                            ppkstrDcmDspSessionRowType[u8SesIndex]->
                            u16DcmDspSessionP2StarServerMax;
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_055();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Enter_Dcm_Access_051();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Enter_Dcm_Access_054();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */
      Dsl_u16P2Counter = Dsl_u16P2Reload;
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_054();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_051();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Enter_Dcm_Access_056();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */
      Dsl_u16P2Adjust = u16P2_SERVER_ADJUST(u8ProtocolIdx);
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Exit_Dcm_Access_056();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */
    }
  }
}

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*! \Description Initializes all static variables of DSL needed to
 *               be initialized
    \return      void
    \Trace_To  CDD-0872(0), CDD-0875(0), CDD-DSL-0016(0), CDD-DSL-0030(0),
               CDD-DSL-0031(0), CDD-DSL-0032(0)
*******************************************************************************/
FUNC(void, DCM_CODE) DslInternal_Init(void)
{
  uint8 u8LoopIdx;

  /*! Set Dsl_udtMainProtRxPduId to 0 */
  Dsl_udtMainProtRxPduId = (PduIdType)0;
  /*! Clear Dsl_bIntTxInProgress */
  Dsl_bIntTxInProgress = FALSE;
  /*! Clear Dsl_bFrcdRCRRPInProgress */
  Dsl_bFrcdRCRRPInProgress = FALSE;
  /*! Clear Dsl_bGeneralRejectPend */
  Dsl_bGeneralRejectPend = FALSE;

#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
  /*! Set Dsl_bPreemptionInProgress to FALSE */
  Dsl_bPreemptionInProgress = FALSE;
  /*! Set Dsl_u8PreemptProtStatus to u8ST_PREEMPT_PROT_IDLE */
  Dsl_u8PreemptProtStatus = u8ST_PREEMPT_PROT_IDLE;
  /*! Clear Dsl_bPreemptTimeoutOn */
  Dsl_bPreemptTimeoutOn = FALSE;
#endif

  /*! IF DCM_bJUMP_TO_BOOT_EN is STD_ON */
  #if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  /*! Set Dsl_u8MainProtocolStatus to u8ST_MN_PROT_BOOT_LDR_CHECK */
  Dsl_u8MainProtocolStatus = u8ST_MN_PROT_BOOT_LDR_CHECK;
  /*! ELSE */
  #else
  /*! Set Dsl_u8MainProtocolStatus to u8ST_MN_PROT_IDLE */
  Dsl_u8MainProtocolStatus = u8ST_MN_PROT_IDLE;
  #endif

  /*! Clear Dsl_bMainProtStarted */
  Dsl_bMainProtStarted = FALSE;

  /*! IF DCM_bPERIODIC_TRANS_ENABLED is STD_ON */
  #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
  /*! Set all periodic protocols status to u8ST_PERIODIC_PROT_IDLE */
  /* !Deviation : Inhibit MISRA rule [2465]: For Loop Only executed once
                  because it is dependent on the configuration                */
  /* PRQA S 2465 ++                                                           */
  for(u8LoopIdx = 0; u8LoopIdx < DCM_u8MAX_NUM_PERIODIC_TX; u8LoopIdx++)
  {
    /* PRQA S 2465 --                                                         */
    Dsl_astrPeriodicProt[u8LoopIdx].udtProtStatus = u8ST_PERIODIC_PROT_IDLE;
  }
  #endif

  /*! IF DCM_bROE_ENABLED is STD_ON */
  #if(DCM_bROE_ENABLED == STD_ON)
  /*! Set Dsl_u16RoeInterMsgCounter to 0 */
  Dsl_u16RoeInterMsgCounter = (uint16)0;
  /*! Set Roe protocol status to IDLE */
  Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_IDLE;
  /*! IF DCM_bDSP_ROE_QUEUE_ENABLED is STD_ON */
  #if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
  /*! Set Dsl_u16RoeQueRear to DCM_u16DSP_ROE_MAX_QUEUE_LENGTH */
  Dsl_u16RoeQueRear  = DCM_u16DSP_ROE_MAX_QUEUE_LENGTH;
  /*! Set Dsl_u16RoeQueFront to DCM_u16DSP_ROE_MAX_QUEUE_LENGTH */
  Dsl_u16RoeQueFront = DCM_u16DSP_ROE_MAX_QUEUE_LENGTH;
  /*! Set Dsl_u8RoeRetryCounter to DCM_u8DSP_ROE_MAX_NUMBER_OF_RETRY */
  Dsl_u8RoeRetryCounter = DCM_u8DSP_ROE_MAX_NUMBER_OF_RETRY;
  /*! Set Dsl_bRoeTransQueStatus to FREE */
  Dsl_bRoeTransQueStatus = u8ST_BUFF_FREE;
  /*! ENDIF */
  #endif
  /*! ENDIF */
  #endif

  /*! Set Dsl_u8MainProtocolIndex to 0 */
  Dsl_u8MainProtocolIndex = (uint8)0;
  /*! Set Dcm_u8eMainProtocolID to the Protocol ID of Dsl_u8MainProtocolIndex */
  Dcm_u8eMainProtocolID = u8PROTOCOL_ID(Dsl_u8MainProtocolIndex);
  
  /*! Initialize Session to default */
  /* Dcm034 */
  Dcm_u8eCurrSesCtrl = DCM_DEFAULT_SESSION;
  /*! Initialize Security Level to LOCKED */
  /* Dcm033 */
  Dcm_u8eCurrSecLevel = DCM_SEC_LEV_LOCKED;

  /*! Load S3 Counter */
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_053();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */
  Dsl_u16S3Reload = u16S3_COUNT;
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_052();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */
  Dsl_u16S3Counter = Dsl_u16S3Reload;
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Exit_Dcm_Access_052();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Exit_Dcm_Access_053();
  /* PRQA S 3138 --                                                         */
  /* PRQA S 3141 --                                                         */

  /*! Reset Dsl_u8RespPendCount to 0 */
  Dsl_u8RespPendCount = (uint8)0;

  /*! Reset indices of all RX/TX buffers and unlock them */
  for(u8LoopIdx = (uint8)0; u8LoopIdx < DCM_u8NUMBER_OF_BUFFERS; u8LoopIdx++)
  {
    Dsl_astrBufferInfo[u8LoopIdx].udtIndex  = (Dcm_MsgLenType)0;
    Dsl_astrBufferInfo[u8LoopIdx].udtStatus = u8ST_BUFF_FREE;
  }

  /*! Clear Dcm_beDiagnosticsActive */
  Dcm_beDiagnosticsActive = FALSE;
}
/******************************************************************************/
/*! \Description Main periodic function of DSL
    \return      void
    \Trace_To  CDD-0877(0), CDD-0878(0), CDD-0879(0), CDD-1194(0), CDD-1188(0),
               CDD-1144(0), CDD-1145(0), CDD-DSL-0015(0), CDD-DSL-0030(0),
               CDD-DSL-0031(0), CDD-DSL-0032(0), CDD-DSL-0035(0),
               CDD-0838(0), CDD-0898(0), CDD-DSL-0050(0), CDD-DSL-0052(0),
               CDD-DSL-0055(0), CDD-DSL-0058(0), CDD-DSL-0059(0),
               CDD-DSL-0062(0), CDD-DSL-0074(0)
*******************************************************************************/
FUNC(void, DCM_CODE) DslInternal_Main(void)
{
  switch(Dsl_u8MainProtocolStatus)
  {
  #if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  /*! If main state is BOOT LOADER CHECK */
  case u8ST_MN_PROT_BOOT_LDR_CHECK:
    /*! Call vidStMainBootloaderCheck() */
    vidStMainBootloaderCheck();
    break;
  #endif
  /*! If main state is IDLE */
  case u8ST_MN_PROT_IDLE:
    /*! Call vidStMainIdle() */
    vidStMainIdle();
    break;
  /*! If main state is PROCESSING */
  case u8ST_MN_PROT_PROCESSING:
    /* Dcm024 */
    /* Dcm027 */
    /*! Call vidHandleBusyResponses() */
    vidHandleBusyResponses();
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
    /*! Call vidHandlePreemptTimeout() */
    vidHandlePreemptTimeout();
#endif
    break;
  /*! If status is Send General Reject */
  case u8ST_MN_PROT_SEND_GR:
    /*! Call vidSendGeneralReject() */
    vidSendGeneralReject();
    break;
  /*! If other main states, call vidHandlePreemptTimeout() */
  case u8ST_MN_PROT_COPYING_RX_DATA: /* Dcm342 */
  case u8ST_MN_PROT_TX_IN_PROGRESS: /* Dcm349 */
  case u8ST_MN_PROT_TX_PENDING:
  case u8ST_MN_PROT_TX_GR_IN_PROGRESS:
  default:
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
    vidHandlePreemptTimeout();
#endif
    break;
  }

#if(DCM_bROE_ENABLED == STD_ON)
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be      */
  /*              implemented during integration phase                */
  /* PRQA S 3141 ++                                                   */
  /* PRQA S 3138 ++                                                   */
  SchM_Enter_Dcm_Access_057();
  /* PRQA S 3138 --                                                   */
  /* PRQA S 3141 --                                                   */
  if(Dsl_u16RoeInterMsgCounter > (uint16)0)
  {
    Dsl_u16RoeInterMsgCounter--;
  }
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be      */
  /*              implemented during integration phase                */
  /* PRQA S 3141 ++                                                   */
  /* PRQA S 3138 ++                                                   */
  SchM_Exit_Dcm_Access_057();
  /* PRQA S 3138 --                                                   */
  /* PRQA S 3141 --                                                   */
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
  /*! Handle transmission of the Roe queued responses. */
  vidSendRoeQuedResponses();
#endif
#endif

#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
  /*! If there is preemption process in progress and cancellation of all
   *  contexts has been finished */
  /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used in
   *              conditional statement for better readability                */
  /* PRQA S 3415 ++                                                           */
  /* PRQA S 3416 ++                                                           */
  if((Dsl_bPreemptionInProgress == TRUE) && (udtAllContextsIdle() == E_OK))
  {
    /* PRQA S 3416 --                                                         */
    /* PRQA S 3415 --                                                         */
    /*! Call vidEndPreemptionProcess() */
    vidEndPreemptionProcess();
    /*! Clear the flag Dsl_bPreemptionInProgress */
    Dsl_bPreemptionInProgress = FALSE;
  }
#endif
}
/******************************************************************************/
/*! \Description Called by DSD when request processing is done \n
    \param[in] idContext ID of the context whose processing is done \n
    \Range     0..255 \n
    \return void \n
    \Trace_To  CDD-0503(0), CDD-0821(0), CDD-0877(0), CDD-0902(0), CDD-0939(0),
               CDD-DSL-0028(0), CDD-DSL-0029(0), CDD-DSL-0030(0),
               CDD-DSL-0031(0), CDD-DSL-0032(0), CDD-0858(0), CDD-0859(0),
               CDD-0061(0), CDD-0062(0), CDD-DSL-0056(0), CDD-DSL-0057(0),
               CDD-DSL-0064(0), CDD-DSL-0065(0)
*******************************************************************************/
FUNC(void, DCM_CODE) DslInternal_ProcessingDone(Dcm_IdContextType idContext)
{
  /* Dcm148, Dcm151, Dcm153, Dcm156, Dcm157, Dcm161, Dcm152 */
  /*! If inContext is Main */
  if(idContext == DspInternal_u8DSL_MAIN_PROT_CONTEXT)
  {
    /*! Call vidMainProcessingDone() */
    vidMainProcessingDone(Dsl_udtMainProtRxPduId);
  }

#if(DCM_bROE_ENABLED == STD_ON)
  /*! Else if the idContext is in the Periodic Transmissions Range */
  else if(idContext == (Dcm_IdContextType)1)
  {
    /*! Call vidRoeProcessingDone() */
    vidRoeProcessingDone();
  }
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
#if(DCM_bROE_ENABLED == STD_ON)
  else if(idContext <= (Dcm_IdContextType)(DCM_u8MAX_NUM_PERIODIC_TX + 1))
#else
  else if(idContext <= DCM_u8MAX_NUM_PERIODIC_TX)
#endif
  {
    /*! Call vidPeriodicProcessingDone() */
    vidPeriodicProcessingDone(idContext);
  }
#endif
  else
  {
    /*! Do nothing. */
  }
}
/******************************************************************************/
/*! \Description Called by lower layer to begin reception of a request \n
    \param[in] DcmRxPduId Rx PduId of received message \n
    \Range     0..255 \n
    \param[in] TpSduLength length of message to be received \n
    \Range     0..65535 \n
    \param[in] RxBufferSizePtr pointer in which the available Rx buffer size is
               put \n
    \Range     Not Null \n
    \return    Flag to indicate if the reception start request is accepted \n
    \Trace_To  CDD-0877(0), CDD-0881(0), CDD-0911(0), CDD-1183(0),
               CDD-1184(0), CDD-1185(0), CDD-1585(0),
               CDD-0508(0), CDD-1469(0), CDD-DSL-0026(0), CDD-DSL-0027(0),
               CDD-DSL-0028(0), CDD-DSL-0029(0), CDD-DSL-0030(0),
               CDD-DSL-0031(0), CDD-DSL-0032(0), CDD-0882(0), CDD-1517(0),
               CDD-1518(0), CDD-DSL-0040(0), CDD-DSL-0045(0), CDD-DSL-0046(0),
               CDD-DSL-0051(0)
*******************************************************************************/
/* Dcm094 */
/* !Deviation : Inhibit MISRA rule [4700]: Metric STSUB threshold is violated
 *              for a better readability  */
/* PRQA S 4700 L1 */
FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReception(
    PduIdType DcmRxPduId,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) RxBufferSizePtr)
{
  BufReq_ReturnType enuReturn = BUFREQ_E_NOT_OK;
  uint8             u8RxProtocolIndex;
  uint8             u8RxBufferId;
#if(DCM_bROE_ENABLED == TRUE)
  uint8             u8RxProtocolPriority;
#endif
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
  boolean           bProtocolPreempt = FALSE;
#endif

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If the DCM is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report DCM_E_UNINIT to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8START_RECEPTION_ID, DCM_E_UNINIT);
  }
  /*! Else if DcmRxPduId > Max configured */
  else if(DcmRxPduId >= u8NUM_PROTOCOL_RX())
  {
    /*! Report DCM_E_PARAM to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8START_RECEPTION_ID, DCM_E_PARAM);
  }
  /*! Else if RxBufferSizePtr is NULL */
  else if(RxBufferSizePtr == NULL_PTR)
  {
    /*! Report DCM_E_NULL_POINTER to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8START_RECEPTION_ID, DCM_E_NULL_POINTER);
  }
  else
  {
#endif
    /* Dcm148 */
    u8RxProtocolIndex = u8RX_PROTOCOL_IDX(DcmRxPduId);
    u8RxBufferId = u8RX_BUFFER_ID(u8RxProtocolIndex);
#if(DCM_bROE_ENABLED == TRUE)
    u8RxProtocolPriority = u8PROT_PRIORITY(u8RxProtocolIndex);
#endif

    /**************************************************************************/
    /*! If TpSduLength is zero */
    if(TpSduLength == (PduLengthType)0)
    {
      /* Dcm642 */
      /*! Set the buffer size into RxBufferSizePtr */
      *RxBufferSizePtr = (PduLengthType)Dcm_kstreDslConfig.
                         astrDcmDslBuffer[u8RxBufferId].udtBufferSize;
      /* ! Let the return value temporarily NOT_OK to skip the rest of the
       *   function. Shall be set OK at the function end. */
    }
    /*! If TpSduLength is larger than the configured */
    else if(TpSduLength > (PduLengthType)Dcm_kstreDslConfig.
                          astrDcmDslBuffer[u8RxBufferId].udtBufferSize)
    {
      /* Dcm444 */
      /*! Set the return value to BUFREQ_E_OVFL */
      enuReturn = BUFREQ_E_OVFL;
    }
#if(DCM_bROE_ENABLED == TRUE)
    /*! Else if the Roe protocol status is not IDLE and the Roe protocol is
     *  higher priority than the new protocol */
    else if((Dsl_strRoeProt.udtProtStatus != u8ST_ROE_PROT_IDLE)
          &&(u8PROT_PRIORITY(Dsl_strRoeProt.u8RoeProtIndex)
          <= u8RxProtocolPriority))
    {
      /*! Set the return value to BUFREQ_E_NOT_OK */
      enuReturn = BUFREQ_E_NOT_OK;
    }
#endif
    else /*! Else, continue with checking the request. */
    {
      /*! Set the return value to BUFREQ_OK */
      enuReturn = BUFREQ_OK;
    }

    /**************************************************************************/
    /**************************************************************************/
    /*! If if the return value is BUFREQ_OK */
    if(enuReturn == BUFREQ_OK)
    {
      /*! If Dsl_bMainProtStarted is cleared and main protocol status is IDLE */
      if((Dsl_bMainProtStarted == FALSE)
       &&(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_IDLE))
      {
        /*! Do nothing. */
      }
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
      /*! Else if the preempting protocol status is not IDLE */
      else if((Dsl_u8PreemptProtStatus != u8ST_PREEMPT_PROT_IDLE)
            ||(Dsl_bPreemptionInProgress == TRUE))
      {
        /*! Set the return value to BUFREQ_E_NOT_OK */
        enuReturn = BUFREQ_E_NOT_OK;
      }
#endif
#if(DCM_bPERIODIC_TRANS_ENABLED == TRUE)
      /*! Else if there is a TYPE1 periodic transmission active */
      /* !Deviation : Inhibit MISRA rule [3416]: function call is used in
       *              conditional statement for better readability            */
      /* PRQA S 3416 ++                                                       */
      else if(udtPeriodicTxTyp1Active() == E_OK)
      {
        /* PRQA S 3416 --                                                     */
        /*! Reject by setting the return value to BUFREQ_E_NOT_OK */
        enuReturn = BUFREQ_E_NOT_OK;
      }
#endif
      /*! Else if there is no request currently being processed. */
      else if(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_IDLE)
      {
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
        /*! Call udtMnIdleStartOfReception() */
        enuReturn = udtMnIdleStartOfReception(DcmRxPduId,
                                              &bProtocolPreempt);
#else
        /*! Call udtMnIdleStartOfReception() */
        enuReturn = udtMnIdleStartOfReception(DcmRxPduId);
#endif
      }
      /*! Else if Main Protocol isn't IDLE => Maybe preemption */
      else
      {
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
        /*! Call udtMnActiveStartOfReception() */
        enuReturn = udtMnActiveStartOfReception(DcmRxPduId,
                                                &bProtocolPreempt);
#else
        /*! Call udtMnActiveStartOfReception() */
        enuReturn = udtMnActiveStartOfReception(DcmRxPduId);
#endif
      }
    }
    /**************************************************************************/
    /**************************************************************************/

    /*! If the return value is BUFREQ_OK */
    if(enuReturn == BUFREQ_OK)
    {
      Dsl_astrBufferInfo[u8RxBufferId].udtIndex = (Dcm_MsgLenType)0;

      *RxBufferSizePtr = (PduLengthType)Dcm_kstreDslConfig.
          astrDcmDslBuffer[u8RxBufferId].udtBufferSize;

#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
      if(bProtocolPreempt == TRUE)
      {
        Dsl_u8PreemptProtStatus = u8ST_PREEMPT_PROT_COPYING_RX_DATA;
        Dsl_udtPreemptRxPduId = DcmRxPduId;
        Dsl_u8PreemptProtocolIndex = u8RxProtocolIndex;
      }
      else
      {
#endif
        Dsl_udtMainProtRxPduId = DcmRxPduId;

        Dsl_u8MainProtocolIndex = u8RxProtocolIndex;
        Dcm_u8eMainProtocolID = u8PROTOCOL_ID(Dsl_u8MainProtocolIndex);
        Dsl_u8MainProtocolStatus = u8ST_MN_PROT_COPYING_RX_DATA; /* Dcm141 */
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
      }
#endif
    }

    if(TpSduLength == (PduLengthType)0)
    {
      enuReturn = BUFREQ_OK; /* Dcm642 */
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif

  return (enuReturn);
}
/* PRQA L:L1 */
/******************************************************************************/
/*! \Description Copy Rx request Data
    \param[in]   DcmRxPduId PduId of the received request \n
    \Range       0..255 \n
    \param[in]   PduInfoPointer Pointer to Pdu Info about data to be copied \n
    \Range       Not Null \n
    \param[in]   RxBufferSizePtr Pointer to remaining available Rx buffer \n
    \Range       Not Null \n
    \return      Flag indicating if the copy operation has succeeded \n
    \Trace_To    CDD-1184(0), CDD-1186(0), CDD-1187(0), CDD-1585(0),
                 CDD-DSL-0026(0), CDD-DSL-0027(0), CDD-DSL-0028(0),
                 CDD-DSL-0029(0), CDD-DSL-0030(0), CDD-DSL-0031(0),
                 CDD-DSL-0032(0)
*******************************************************************************/
/* Dcm556 */
FUNC(BufReq_ReturnType,DCM_CODE) Dcm_CopyRxData(
  PduIdType DcmRxPduId,
  /* !Deviation : Inhibit MISRA rule [3673]: Although data pointed by this
   *              pointer is not modified, AUTOSAR specifies this prototype   */
  /* PRQA S 3673 ++                                                           */
  P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPointer,
  /* PRQA S 3673 --                                                           */
  P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) RxBufferSizePtr )
{
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  BufReq_ReturnType enuReturn = BUFREQ_E_NOT_OK;
#else
  BufReq_ReturnType enuReturn;
#endif
  uint8             u8RxBufferId;
  uint8             u8RxProtocolIndex;
  uint32            u32RxBufferIndex;
  PduLengthType     udtLoopIndex;
  PduLengthType     udtAvailableBufferSize;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COPY_RX_DATA_ID, DCM_E_UNINIT);
  }
  else if(DcmRxPduId >= u8NUM_PROTOCOL_RX())
  {
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COPY_RX_DATA_ID, DCM_E_PARAM);
  }
  else if((PduInfoPointer == NULL_PTR) || (RxBufferSizePtr == NULL_PTR))
  {
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COPY_RX_DATA_ID, DCM_E_NULL_POINTER);
  }
  else
  {
#endif
    /* Dcm148 */
    u8RxProtocolIndex = u8RX_PROTOCOL_IDX(DcmRxPduId);
    u8RxBufferId = u8RX_BUFFER_ID(u8RxProtocolIndex);

    if(Dsl_astrBufferInfo[u8RxBufferId].udtStatus == u8ST_BUFF_LOCKED)
    {
      /* Dcm445, Dcm241 */
      enuReturn = BUFREQ_E_BUSY;
    }
    else
    {
      enuReturn = BUFREQ_OK;
    }

    if(enuReturn == BUFREQ_OK)
    {
      /* Dcm443 */
      u32RxBufferIndex = Dsl_astrBufferInfo[u8RxBufferId].udtIndex;
      udtAvailableBufferSize =
               (PduLengthType)(udtBUFFER_SIZE(u8RxBufferId) - u32RxBufferIndex);

      /*! If required copy length is larger than 0 */
      if(PduInfoPointer->SduLength > (PduLengthType)0)
      {
        /*! If the required copy length is larger than the free buffer size */
        if(PduInfoPointer->SduLength > udtAvailableBufferSize)
        {
          /*! return BUFREQ_E_NOT_OK */
          enuReturn = BUFREQ_E_NOT_OK;
        }
        /*! else, copy the required length of data */
        else
        {
          for(udtLoopIndex = (PduLengthType)0;
              udtLoopIndex < PduInfoPointer->SduLength;
              udtLoopIndex++)
          {
            Dcm_kstreDslConfig.
            astrDcmDslBuffer[u8RxBufferId].
            pudtBuffer[u32RxBufferIndex+udtLoopIndex] =PduInfoPointer->
                                                       SduDataPtr[udtLoopIndex];
          }

          /*! Update the buffer index after copying the Rx data */
          Dsl_astrBufferInfo[u8RxBufferId].udtIndex =
          Dsl_astrBufferInfo[u8RxBufferId].udtIndex + PduInfoPointer->SduLength;
        }
      }

      /*! Update the Remaining free space in receive buffer after completion of
        this call. */
      *RxBufferSizePtr = (PduLengthType)(udtBUFFER_SIZE(u8RxBufferId) -
                         Dsl_astrBufferInfo[u8RxBufferId].udtIndex);
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif

  return (enuReturn);
}
/******************************************************************************/
/*! \Description Used to indicate the end of request reception
    \param[in]   DcmRxPduId   ID of DCM I-PDU that has been received. \n
                 Identifies the data that has been received. \n
    \Range       0..(maximum number of I-PDU IDs received by DCM) minus 1 \n
    \param[in]   Result 
                 - NTFRSLT_OK: the complete N-PDU has been received and\n
                 is stored in the receive buffer \n
                 - any other value: the N_PDU has not been received; the  \n
                 receive buffer can be unlocked by the DCM. \n
    \Range       range of NotifResultType \n
    \return      void \n
    \Trace_To  CDD-0815(0), CDD-0816(0), CDD-0817(0), CDD-0818(0), CDD-0877(0),
               CDD-0892(0), CDD-0893(0),
               CDD-0894(0), CDD-0895(0), CDD-0896(0), CDD-0899(0), CDD-0904(0),
               CDD-0905(0), CDD-1190(0), CDD-1191(0), CDD-0942(0), CDD-1189(0),
               CDD-1536(0), CDD-DSL-0026(0), CDD-DSL-0027(0), CDD-DSL-0028(0),
               CDD-DSL-0029(0), CDD-DSL-0030(0), CDD-DSL-0031(0),
               CDD-DSL-0032(0), CDD-0337(0), CDD-0883(0), CDD-0884(0),
               CDD-0885(0), CDD-DSL-0038(0), CDD-0888(0), CDD-0889(0),
               CDD-0890(0), CDD-DSL-0039(0), CDD-DSL-0047(0), CDD-DSL-0048(0),
               CDD-DSL-0049(0)
*******************************************************************************/
/* Dcm093 */
/* Dcm345 */
FUNC(void, DCM_CODE) Dcm_TpRxIndication(PduIdType DcmRxPduId,
                                      NotifResultType Result)
{
#if(DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If Dcm is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report DCM_E_UNINIT to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8RX_INDICATION_ID, DCM_E_UNINIT);
  }
  /*! Else if the passed DcmRxPduId is not in the configured range */
  else if(DcmRxPduId >= u8NUM_PROTOCOL_RX())
  {
    /*! Report DCM_E_PARAM to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8RX_INDICATION_ID, DCM_E_PARAM);
  }
  /*! Else */
  else
  {
#endif

    /* Dcm148 */
    /*! If DcmRxPduId is of the main protocol  */
    if(DcmRxPduId == Dsl_udtMainProtRxPduId)
    {
      vidMainRxIndication(DcmRxPduId, Dsl_udtMainProtRxPduId, Result);
    }
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
    /*! Else if the PduId is the preempting one */
    else if((DcmRxPduId == Dsl_udtPreemptRxPduId)
         && (Dsl_u8PreemptProtStatus == u8ST_PREEMPT_PROT_COPYING_RX_DATA))
    {
      vidPreemptRxIndication(DcmRxPduId, Dsl_udtMainProtRxPduId, Result);
    }
#endif
    /*! Else if DcmRxPduId is neither of the main protocol nor the preempting
     * one */
    else
    {
      /*! Do nothing. */
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
}
/******************************************************************************/
/*! \Description At invocation of Dcm_CopyTxData the DCM module copy the \n
 *               requested transmit data with ID PduId from its internal \n
 *               transmit buffer to the location specified by the PduInfoPtr. \n
 *               The function Dcm_CopyTxData also calculates and sets the \n
 *               TxDataCntPtr to the amount of remaining bytes for the  \n
 *               transmission of this data.
    \param[in]   DcmTxPduId Tx PduId \n
    \Range       0..255 \n
    \param[in]   PduInfoPtr pointer to Pdu Info \n
    \Range       Not Null \n
    \param[in]   RetryInfoPtr pointer to Retry Info \n
    \Range       Not Null \n
    \param[in]   TxDataCntPtr Remaining Tx data after completion of this call \n
    \Range       Null \n
    \return      BUFREQ_OK: Data has been copied to the transmit buffer
                 completely as requested.
                 BUFREQ_E_NOT_OK: Data has not been copied. Request
                 failed, in case the corresponding I-PDU was stopped. \n
    \Trace_To    CDD-1193(0), CDD-1192(0), CDD-DSL-0026(0), CDD-DSL-0027(0),
                 CDD-DSL-0028(0), CDD-DSL-0029(0), CDD-DSL-0030(0),
                 CDD-DSL-0031(0), CDD-DSL-0032(0), CDD-DSL-0068(0),
                 CDD-DSL-0069(0), CDD-DSL-0070(0)
*******************************************************************************/
/* Dcm092, Dcm350 */
/* !Deviation : Inhibit MISRA rule [3206]: Autosar specs don't specify how to
                use RetryInfoPtr                                              */
/* PRQA S 3206 ++                                                             */
/* !Deviation : Inhibit MISRA rule [4700]: Metrics threshold is violated
 *              for a better readability  */
/* PRQA S 4700 ++ */
BufReq_ReturnType Dcm_CopyTxData(
    PduIdType DcmTxPduId,
    P2VAR(PduInfoType,AUTOMATIC,DCM_APPL_DATA) PduInfoPtr,
    /* !Deviation : Inhibit MISRA rule [3673]: Although data pointed by this
     *              pointer is not modified, AUTOSAR specifies this prototype */
    /* PRQA S 3673 ++                                                         */
    P2VAR(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) RetryInfoPtr,
    /* PRQA S 3673 --                                                         */
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr )
{
  BufReq_ReturnType udtReturn = BUFREQ_OK;
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
  uint8             u8PeriodicProtArrIdx;
#endif

  /*! IF DET is enabled */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If Dcm is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report DCM_E_UNINIT to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COPY_TX_DATA_ID, DCM_E_UNINIT);
    /*! Return NOT_OK */
    udtReturn = BUFREQ_E_NOT_OK;
  }
  /*! Else if PduInfoPtr or TxDataCntPtr is NULL */
  else if((PduInfoPtr == NULL_PTR)||(TxDataCntPtr == NULL_PTR))
  {
    /*! Report DCM_E_NULL_POINTER to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COPY_TX_DATA_ID, DCM_E_NULL_POINTER);
    /*! Return NOT_OK */
    udtReturn = BUFREQ_E_NOT_OK;
  }
  /*! Else if RetryInfoPtr is not NULL */
  else if(RetryInfoPtr != NULL_PTR)
  {
    /*! Report DCM_E_PARAM to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COPY_TX_DATA_ID, DCM_E_PARAM);
    /*! Return NOT_OK */
    udtReturn = BUFREQ_E_NOT_OK;
  }
  /*! Else */
  else
  {
#endif

    /* Dcm148 */
    /*! If DcmTxPduId is of the main protocol */
    if(DcmTxPduId == udtTX_PDU_REF(Dsl_udtMainProtRxPduId))
    {
      switch(Dsl_u8MainProtocolStatus)
      {
      /*! If main protocol status is PROCESSING */
      case u8ST_MN_PROT_PROCESSING:
      case u8ST_MN_PROT_GR_TX_PENDING:
      case u8ST_MN_PROT_WAIT_TO_END_PRCS:
        /*! If Dsl_bIntTxInProgress or Dsl_bFrcdRCRRPInProgress is true */
        if(  (Dsl_bIntTxInProgress == TRUE)
          || (Dsl_bFrcdRCRRPInProgress == TRUE) )
        {
          /*! Set the first three bytes of the destination buffer with the
           *  values of the Dsl_au8InternalTxBuffer[] */
          PduInfoPtr->SduDataPtr[0] = Dsl_au8InternalTxBuffer[0];
          PduInfoPtr->SduDataPtr[1] = Dsl_au8InternalTxBuffer[1];
          PduInfoPtr->SduDataPtr[2] = Dsl_au8InternalTxBuffer[2];
          /*! Set value of TxDataCntPtr to 0 */
          *TxDataCntPtr = (PduLengthType)0;
        }
        /*! Else */
        else
        {
          /*! Return NOT_OK */
          udtReturn = BUFREQ_E_NOT_OK;
        }
        break;

      /*! Else if the main protocol status is TX_GR_IN_PROGRESS */
      case u8ST_MN_PROT_TX_GR_IN_PROGRESS:
        /*! Set the first three bytes of the destination buffer with the
         *  values of the Dsl_au8InternalTxBuffer[] */
        PduInfoPtr->SduDataPtr[0] = Dsl_au8InternalTxBuffer[0];
        PduInfoPtr->SduDataPtr[1] = Dsl_au8InternalTxBuffer[1];
        PduInfoPtr->SduDataPtr[2] = Dsl_au8InternalTxBuffer[2];
        /*! Set value of TxDataCntPtr to 0 */
        *TxDataCntPtr = (PduLengthType)0;
        break;
      /*! Else if the main protocol status is TX_PENDING */
      case u8ST_MN_PROT_TX_PENDING:
        /*! Set the first three bytes of the destination buffer with the
         *  values of the Dsl_au8InternalTxBuffer[] */
        PduInfoPtr->SduDataPtr[0] = Dsl_au8InternalTxBuffer[0];
        PduInfoPtr->SduDataPtr[1] = Dsl_au8InternalTxBuffer[1];
        PduInfoPtr->SduDataPtr[2] = Dsl_au8InternalTxBuffer[2];
        /*! Set value of TxDataCntPtr to 0 */
        *TxDataCntPtr = (PduLengthType)0;
        break;

      /*! Else if main protocol status is either
       *  u8ST_MN_PROT_TX_BT_LDR_IN_PROGRESS, u8ST_MN_PROT_TX_CNC_IN_PROGRESS,
       *  or u8ST_MN_PROT_TX_IN_PROGRESS */
      case u8ST_MN_PROT_TX_BT_LDR_IN_PROGRESS:
      case u8ST_MN_PROT_TX_CNC_IN_PROGRESS:
      case u8ST_MN_PROT_TX_IN_PROGRESS:
        /*! Call udtMainCopyFromTxBuffer() */
        udtReturn = udtMainCopyFromTxBuffer(DcmTxPduId, PduInfoPtr,
            TxDataCntPtr);
        break;

      /*! IF DCM_PAGED_BUFFER_ENABLED is ON */
      #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
      case u8ST_MN_PROT_PAGE_DATA_PROCESSED: /*Dcm028*/
        udtReturn = udtMainPageCopyFromTxBuffer(DcmTxPduId, PduInfoPtr,
            TxDataCntPtr);
        break;
        /*! If main status is u8ST_MN_PROT_PAGE_UPDATE_REQUESTED */
      case u8ST_MN_PROT_PAGE_UPDATE_REQUESTED:
        /*! Return Busy */
        udtReturn = BUFREQ_E_BUSY;
        break;
      #endif

        /*! IF ROE or Periodic Transmission is enabled */
#if((DCM_bROE_ENABLED == STD_ON) || (DCM_bPERIODIC_TRANS_ENABLED))
        /*! If main protocol status is IDLE */
      case u8ST_MN_PROT_IDLE:
      /*! IF ROE is enabled */
      #if(DCM_bROE_ENABLED == STD_ON)
        /*! If DcmTxPduId equals Dsl_strRoeProt.udtTxPduRef */
        if(DcmTxPduId == Dsl_strRoeProt.udtRoeTxPduRef)
        {
          if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_TX_IN_PROGRESS)
          {
            /*! Call udtRoeCopyFromTxBuffer() */
            udtReturn = udtRoeCopyFromTxBuffer(PduInfoPtr, TxDataCntPtr);
          }
          #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
          else if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_PAGE_DATA_PROCESSED)
          {
            udtReturn = udtRoePageCopyFromTxBuffer(PduInfoPtr, TxDataCntPtr);
          }
          #endif
          else
          {
            /*! Do nothing */
          }
        }
      #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
        else
      #endif
      #endif
      /*! IF Periodic Transmission is enabled */
      #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
        /*! If DcmTxPduId is one of the periodic TX PduIdRef's  */
        /* !Deviation : Inhibit MISRA rule [3416]: function call is used in
         *              conditional statement for better readability          */
        /* PRQA S 3416 ++                                                     */
        if(udtIsPeriodicTxPduRef(DcmTxPduId, &u8PeriodicProtArrIdx) == E_OK)
        {
          /* PRQA S 3416 --                                                   */
          if(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus ==
              u8ST_PERIODIC_PROT_TX_IN_PROGRESS)
          {
            /*! Call udtPeriodicCopyFromTxBuffer() */
            udtReturn = udtPeriodicCopyFromTxBuffer(u8PeriodicProtArrIdx,
                PduInfoPtr, TxDataCntPtr);
          }
          #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
          else if(Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus ==
              u8ST_PERIODIC_PROT_PAGE_DATA_PROCESSED)
          {
            udtReturn = udtPeriodicPageCopyFromTxBuffer(u8PeriodicProtArrIdx,
                            PduInfoPtr, TxDataCntPtr);
          }
          #endif
          else
          {
            /*! Do nothing */
          }
        }
        else
        {
          /*! Do nothing. */
        }
      #endif
        break;
#endif
      /*! Else if main protocol status is otherwise */
      default:
        /*! Return BUFREQ_E_NOT_OK */
        udtReturn = BUFREQ_E_NOT_OK;
        break;
      }
    }
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
    /*! Else if DcmTxPduId is of the preempting protocol */
    else if(DcmTxPduId == udtTX_PDU_REF(Dsl_udtPreemptRxPduId))
    {
      /*! Call udtPreemptCopyFromTxBuffer */
      udtReturn = udtPreemptCopyFromTxBuffer(PduInfoPtr, TxDataCntPtr);
    }
#endif
#if(DCM_bROE_ENABLED == STD_ON)
    /*! Else if DcmTxPduId is the TYPE2 Roe TxPduRef */
    else if(DcmTxPduId == Dsl_strRoeProt.udtRoeTxPduRef)
    {
      /*! Call udtRoeCopyFromTxBuffer() */
      udtReturn = udtRoeCopyFromTxBuffer(PduInfoPtr, TxDataCntPtr);
    }
#endif
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
    /*! Else if DcmTxPduId is a TYPE2 Periodic TxPduRef */
    /* !Deviation : Inhibit MISRA rule [3416]: function call is used in
     *              conditional statement for better readability              */
    /* PRQA S 3416 ++                                                         */
    else if(udtIsPeriodicTxPduRef(DcmTxPduId, &u8PeriodicProtArrIdx) == E_OK)
    {
      /* PRQA S 3416 --                                                       */
      /*! Call udtPeriodicCopyFromTxBuffer() */
      udtReturn = udtPeriodicCopyFromTxBuffer(u8PeriodicProtArrIdx, PduInfoPtr,
          TxDataCntPtr);
    }
#endif
    /*! Else if invalid DcmTxPduId */
    else
    {
      /*! Return BUFREQ_E_NOT_OK */
      udtReturn = BUFREQ_E_NOT_OK;
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif

  return udtReturn;
}
/* PRQA S 4700 -- */
/* PRQA S 3206 --                                                             */
/******************************************************************************/
/*! \Description This is called by the PduR to confirm a Transmit \n
    \param[in]   DcmTxPduId ID of DCM I-PDU that has been transmitted. \n
    \Range       0..(maximum number of I-PDU IDs transmitted by DCM) minus 1 \n
    \param[in]   Result 
                 - NTFRSLT_OK if the complete N-PDU has been \n
                 transmitted. \n
                 - NTFRSLT_E_CANCELATION_OK if the N-PDU has been successfully\n
                 cancelled \n
                 - NTFRSLT_E_CANCELATION_NOT_OK if an error occurred when \n
                 cancelling the N-PDU \n
                 - any other value: an error occurred during transmission, the\n
                 DCM can unlock the transmit buffer \n
    \Range       range of NotifResultType \n
    \return      void \n
    \Trace_To  CDD-0503(0), CDD-0821(0), CDD-0822(0), CDD-0877(0),
               CDD-0897(0), CDD-0900(0), CDD-0906(0), CDD-0939(0), CDD-0940(0),
               CDD-1196(0), CDD-1197(0), CDD-1198(0), CDD-1199(0),
               CDD-DSL-0027(0), CDD-DSL-0028(0), CDD-DSL-0029(0),
               CDD-DSL-0030(0), CDD-DSL-0031(0), CDD-DSL-0032(0),
               CDD-0886(0)
*******************************************************************************/
/* Dcm351, Dcm354 */
/* !Deviation : Inhibit MISRA rule [4700]: Metrics threshold is violated
 *              for a better readability  */
/* PRQA S 4700 ++ */
FUNC(void, DCM_CODE) Dcm_TpTxConfirmation(PduIdType DcmTxPduId,
                                          NotifResultType Result)
{
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8TX_CONFIRMATION_ID, DCM_E_UNINIT);
  }
  else if(DcmTxPduId >= u8NUM_PROTOCOL_TX())
  {
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8TX_CONFIRMATION_ID, DCM_E_PARAM);
  }
  else
  {
#endif

    /* Dcm148 */
    /*! If PduId is of the main protocol */
    if(u8PROTOCOL_IDX(DcmTxPduId) == Dsl_u8MainProtocolIndex)
    {
      /*! Call vidMainTxConfirmation() */
      vidMainTxConfirmation(Result);
    }
#if(DCM_bPROT_PREEMPT_ENABLED == STD_ON)
    /*! Else if the TxPduId is of the preempting protocol */
    else if(u8PROTOCOL_IDX(DcmTxPduId) == Dsl_u8PreemptProtocolIndex)
    {
      switch(Dsl_u8PreemptProtStatus)
      {
      /*! If the preempting protocol status is TX_IN_PROGRESS or
       *  TX_CNC_IN_PROGRESS */
      case u8ST_PREEMPT_PROT_TX_IN_PROGRESS:
      case u8ST_PREEMPT_PROT_TX_CNC_IN_PROGRESS:
        /*! End the preempting protocol */
        vidEndOfPreemptMsgExec();
        break;

      default:
        break;
      }
    }
#endif
    /*! Else (not the main TxPduId nor the preemting TxPduId) */
    else
    {
      #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
      vidPeriodicTxConfirmation(DcmTxPduId, Result);
      #endif
      #if(DCM_bROE_ENABLED == STD_ON)
      vidRoeTxConfirmation(DcmTxPduId, Result);
      #endif
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
}
/* PRQA S 4700 -- */
/******************************************************************************/
/*! \Description This call informs the Dcm module about a ComM mode change to
 *               COMM_NO_COMMUNICATION. \n
    \param[in]   NetworkId Identifier of the network concerned by the mode
                 change \n
    \Range       0..255 \n
    \return      void \n
    \Trace_To    CDD-1200(0), CDD-3009(0), CDD-DSL-0027(0), CDD-DSL-0028(0),
                 CDD-DSL-0029(0), CDD-DSL-0030(0), CDD-DSL-0031(0),
                 CDD-DSL-0032(0)
*******************************************************************************/
/* Dcm356 */
FUNC(void,DCM_CODE) Dcm_ComM_NoComModeEntered(
    /* !Deviation : Inhibit MISRA rule [3206]: Due to AUTOSAR bug#45313, this
     *              interface is not implemented.                             */
    /* PRQA S 3206 ++                                                         */
    uint8 NetworkId
    /* PRQA S 3206 --                                                         */
    )
{
  /*! If Development Error Tracing is ON */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If DCM is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report DCM_E_UNINIT error to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COMM_NO_COM_ID, DCM_E_UNINIT);
  }
#endif
}
/******************************************************************************/
/*! \Description This call informs the Dcm module about a ComM mode change to
 *               COMM_SILENT_COMMUNICATION. \n
    \param[in]   NetworkId Identifier of the network concerned by the mode
                 change \n
    \Range       0..255 \n
    \return      void \n
    \Trace_To  CDD-1470(0), CDD-3009(0), CDD-DSL-0027(0), CDD-DSL-0028(0),
               CDD-DSL-0029(0), CDD-DSL-0030(0), CDD-DSL-0031(0),
               CDD-DSL-0032(0)
*******************************************************************************/
/* Dcm358 */
FUNC(void,DCM_CODE) Dcm_ComM_SilentComModeEntered(
    /* !Deviation : Inhibit MISRA rule [3206]: Due to AUTOSAR bug#45313, this
     *              interface is not implemented.                             */
    /* PRQA S 3206 ++                                                         */
    uint8 NetworkId
    /* PRQA S 3206 --                                                         */
    )
{
  /*! If Development Error Tracing is ON */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If DCM is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report DCM_E_UNINIT error to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COMM_SILENT_COM_ID, DCM_E_UNINIT);
  }
#endif
}
/******************************************************************************/
/*! \Description This call informs the Dcm module about a ComM mode change to
 *               COMM_FULL_COMMUNICATION. \n
    \param[in]   NetworkId Identifier of the network concerned by the mode
                 change \n
    \Range       0..255 \n
    \return      void \n
    \Trace_To  CDD-1501(0), CDD-3009(0), CDD-DSL-0027(0), CDD-DSL-0028(0),
               CDD-DSL-0029(0), CDD-DSL-0030(0), CDD-DSL-0031(0),
               CDD-DSL-0032(0)
*******************************************************************************/
/* Dcm360 */
FUNC(void, DCM_CODE) Dcm_ComM_FullComModeEntered(
    /* !Deviation : Inhibit MISRA rule [3206]: Due to AUTOSAR bug#45313, this
     *              interface is not implemented.                             */
    /* PRQA S 3206 ++                                                         */
    uint8 NetworkId
    /* PRQA S 3206 --                                                         */
    )
{
  /*! If Development Error Tracing is ON */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If DCM is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report DCM_E_UNINIT error to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8COMM_FULL_COM_ID, DCM_E_UNINIT);
  }
#endif
}
/******************************************************************************/
/*! \Description Gets Current Security Level \n
    \param[in]   SecLevel pointer in which current security level is copied \n
    \Range       0..255 \n
    \return      Always OK \n
    \Trace_To  CDD-0871(0), CDD-1178(0), CDD-DSL-0026(0), CDD-DSL-0027(0),
               CDD-DSL-0028(0), CDD-DSL-0029(0), CDD-DSL-0030(0),
               CDD-DSL-0031(0), CDD-DSL-0032(0)
*******************************************************************************/
/* Dcm338 */
/* !Deviation : Inhibit MISRA rule [3204]: The return value is changed to
                NOT_OK when DET is configured ON.                             */
/* PRQA S 3204 ++                                                             */
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSecurityLevel(
    P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_APPL_DATA) SecLevel)
{
  Std_ReturnType udtReturn = E_OK;

  /*! If Development Error Tracing is ON */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If DCM is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report error to DET and return NOT OK. */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8GET_SECURITY_LVL_ID, DCM_E_UNINIT);
    udtReturn = E_NOT_OK;
  }
  /*! Else If the input pointer is NULL */
  else if(SecLevel == NULL_PTR)
  {
    /*! Report error to DET and return NOT OK. */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8GET_SECURITY_LVL_ID, DCM_E_NULL_POINTER);
    udtReturn = E_NOT_OK;
  }
  /*! Else */
  else
  {
#endif /* (DCM_DEV_ERROR_DETECT == STD_ON) */

    /*! Assign the active Security Level to the input pointer. */
    /*! Return OK */
    *SecLevel = Dcm_u8eCurrSecLevel;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif

  return (udtReturn);
}
/* PRQA S 3204 --                                                             */

/******************************************************************************/
/*! \Description Gets Current Session Control Type \n
    \param[in]   Pointer in which current session control type is copied \n
    \Range       0..255 \n
    \return      Always OK \n
    \Trace_To    CDD-0874(0), CDD-1179(0), CDD-DSL-0026(0), CDD-DSL-0027(0),
                 CDD-DSL-0028(0), CDD-DSL-0029(0), CDD-DSL-0030(0),
                 CDD-DSL-0031(0), CDD-DSL-0032(0)
*******************************************************************************/
/* Dcm339 */
/* !Deviation : Inhibit MISRA rule [3204]: The return value is changed to
                NOT_OK when DET is configured ON.                             */
/* PRQA S 3204 ++                                                             */
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType(
    P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA) SesCtrlType)
{
  Std_ReturnType udtReturn = E_OK;

/*! If Development Error Tracing is ON */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If DCM is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report error to DET and return NOT OK. */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8GET_SES_CTRL_TYPE_ID, DCM_E_UNINIT);

    udtReturn = E_NOT_OK;
  }
  /*! Else If the input pointer is NULL */
  else if(SesCtrlType == NULL_PTR)
  {
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8GET_SES_CTRL_TYPE_ID, DCM_E_NULL_POINTER);

    udtReturn = E_NOT_OK;
  }
  /*! Else */
  else
  {
#endif /* (DCM_DEV_ERROR_DETECT == STD_ON) */

    /*! Assign the active Session Control Type to the input pointer. */
    /*! Return OK */
    *SesCtrlType = Dcm_u8eCurrSesCtrl;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif

  return (udtReturn);
}
/* PRQA S 3204 --                                                             */

/******************************************************************************/
/*! \Description Gets Active Protocol \n
    \param[in]   Pointer in which active protocol is copied \n
    \Range       0..255 \n
    \return      Always OK \n
    \Trace_To  CDD-1180(0), CDD-DSL-0026(0), CDD-DSL-0027(0), CDD-DSL-0028(0),
               CDD-DSL-0029(0), CDD-DSL-0030(0), CDD-DSL-0031(0),
               CDD-DSL-0032(0)
*******************************************************************************/
/* Dcm340 */
/* !Deviation : Inhibit MISRA rule [3204]: The return value is changed to
                NOT_OK when DET is configured ON.                             */
/* PRQA S 3204 ++                                                             */
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetActiveProtocol(
    P2VAR(Dcm_ProtocolType, AUTOMATIC, DCM_APPL_DATA) ActiveProtocol)
{
  Std_ReturnType udtReturn = E_OK;

/*! If Development Error Tracing is ON */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If DCM is not initialized*/
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report DCM_E_UNINIT to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8GET_ACTIVE_PRTCL_ID, DCM_E_UNINIT);
    /*! Return NOT OK */
    udtReturn = E_NOT_OK;
  }
  /*! Else if ActiveProtocol pointer is null */
  else if(ActiveProtocol == NULL_PTR)
  {
    /*! Report DCM_E_NULL_POINTER to DET */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                    Dcm_u8GET_ACTIVE_PRTCL_ID, DCM_E_NULL_POINTER);
    /*! Return NOT OK */
    udtReturn = E_NOT_OK;
  }
  /*! Else if DCM is initialized */
  else
  {
#endif

    /*! Set ActiveProtocol with the current protocol ID */
    *ActiveProtocol = Dcm_pkstrePbConfig->strPbDcmDslConfig.
    pkstrDcmDslProtocolRow[Dsl_u8MainProtocolIndex].
    u8DcmDslProtocolID;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif

  return (udtReturn);
}
/* PRQA S 3204 --                                                             */

/******************************************************************************/
/*! \Description Sets Security Level \n
    \param[in]   New Security Level \n
    \Range       0..255 \n
    \return      void \n
    \Trace_To    CDD-1563(0)
*******************************************************************************/
FUNC(void, DCM_CODE) DslInternal_SetSecurityLevel(
    Dcm_SecLevelType SecurityLevel)
{
  /*! Set SecurityLevel with the currently active session level */
  Dcm_u8eCurrSecLevel = SecurityLevel;
}
/******************************************************************************/
/*! \Description Sets Session Control Type \n
    \param[in]   New Session Control Type \n
    \Range       0..255 \n
    \return      void \n
    \Trace_To  CDD-0903(0), CDD-0904(0), CDD-1564(0), CDD-DSL-0018(0),
               CDD-DSL-0033(0)
*******************************************************************************/
FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType(
    Dcm_SesCtrlType SesCtrlType)
{
  /*! Call DspInternal_vidSessionTransNotify() */
  DspInternal_vidSessionTransNotify(Dcm_u8eCurrSesCtrl, SesCtrlType);

  /* Dcm167 */
  /*! If the current session is default and the requested session is
   *  not default */
  if((SesCtrlType != DCM_DEFAULT_SESSION) &&
     (Dcm_u8eCurrSesCtrl == DCM_DEFAULT_SESSION))
  {
    /*! Activate Diagnostics */
    ComM_DCM_ActiveDiagnostic(u8NETWORK_ID(Dsl_udtMainProtRxPduId));
    Dcm_beDiagnosticsActive = TRUE;
    /* Dcm311 */
    /*! Reload the new session timers */
    vidReloadSessionTimers(Dsl_u8MainProtocolIndex, SesCtrlType);
    /*! Set the current session with the requested one */
    Dcm_u8eCurrSesCtrl = SesCtrlType;
  }
  /* Dcm168, Dcm139 */
  /*! Else If the current session is not default and the requested session is
     *  default */
  else if((SesCtrlType == DCM_DEFAULT_SESSION) &&
          (Dcm_u8eCurrSesCtrl != DCM_DEFAULT_SESSION))
  {
    /*! Inactivate Diagnostics */
    ComM_DCM_InactiveDiagnostic(u8NETWORK_ID(Dsl_udtMainProtRxPduId));
    Dcm_beDiagnosticsActive = FALSE;
    /* Dcm311 */
    /*! Reload the new session timers */
    vidReloadSessionTimers(Dsl_u8MainProtocolIndex, SesCtrlType);
    /*! Set the current security level to LOCKED */
    Dcm_u8eCurrSecLevel = DCM_SEC_LEV_LOCKED;
    /*! Set the current session with the requested one */
    Dcm_u8eCurrSesCtrl = SesCtrlType;
    /*! If Periodic Transmissions is enabled */
    #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
    /*! Call vidCancelPeriodicContext() */
    vidCancelPeriodicContext();
    #endif
    /* Dcm597 */
    /*! If ROE is enabled and DCM_bDSP_ROE_INIT_ON_DSC is ON */
    #if((DCM_bROE_ENABLED == STD_ON) && (DCM_bDSP_ROE_INIT_ON_DSC == STD_ON))
    /*! Call vidCancelRoeContext() */
    vidCancelRoeContext();
    #endif
  }
  /* Dcm139 */
  /*! Else If the current session is not default and the requested session is
   *  not default */
  else if(SesCtrlType != DCM_DEFAULT_SESSION)
  {
    /* Dcm311 */
    /*! Reload the new session timers */
    vidReloadSessionTimers(Dsl_u8MainProtocolIndex, SesCtrlType);
    /*! Set the current security level to LOCKED */
    Dcm_u8eCurrSecLevel = DCM_SEC_LEV_LOCKED;
    /*! Set the current session with the requested one */
    Dcm_u8eCurrSesCtrl = SesCtrlType;
  }
  /*! Else, do nothing */
  else
  {
    /* Do nothing. */
  }
}
/******************************************************************************/
/*! \Description Resets to default session
    \return      Always OK
    \Trace_To    CDD-1181(0), CDD-DSL-0026(0), CDD-DSL-0027(0), CDD-DSL-0028(0),
                 CDD-DSL-0030(0), CDD-DSL-0031(0), CDD-DSL-0032(0)
*******************************************************************************/
/* Dcm520 */
/* !Deviation : Inhibit MISRA rule [3204]: The return value is changed to
                NOT_OK when DET is configured ON.                             */
/* PRQA S 3204 ++                                                             */
FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetToDefaultSession(void)
{
  Std_ReturnType udtReturn = E_OK;

/*! If Development Error Tracing is ON */
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If DCM is not initialized */
  if(Dcm_beInitDone == FALSE)
  {
    /*! Report DCM_E_UNINIT error to DET and return NOT OK. */
    Det_ReportError(DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
        Dcm_u8RST_TO_DEF_SESS_ID, DCM_E_UNINIT);
    udtReturn = E_NOT_OK;
  }
  /*! Else */
  else
  {
#endif /* (DCM_DEV_ERROR_DETECT == STD_ON) */

    /*! Call BswM_Dcm_RequestSessionMode() with the default session */
    BswM_Dcm_RequestSessionMode(DCM_DEFAULT_SESSION);

    /*! If the requested session is accepted by the BswM */
    if(Dcm_u8eRequestedSesMode == DCM_DEFAULT_SESSION)
    {
      /*! Call DslInternal_SetSesCtrlType() with the default session */
      DslInternal_SetSesCtrlType(DCM_DEFAULT_SESSION);
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif

  return (udtReturn);
}
/* PRQA S 3204 --                                                             */

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Notifies DSL of the page processing failure so that DSL starts
 *               cancellation of the context
    \param[in]   u8IdContext Id of the failed context \n
    \Range       0..255 \n
    \return      void   \n
    \Trace_To    CDD-DSL-0071(0)
*******************************************************************************/
FUNC(void, DCM_CODE) DslInternal_PageBufferFailed(Dcm_IdContextType u8IdContext)
{
  /*! If u8IdContext is the main */
  if(u8IdContext == DspInternal_u8DSL_MAIN_PROT_CONTEXT)
  {
    /*! Raise cancel bit of Dsl_strMainProtMsgContext */
    Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation = TRUE;
  }
  #if(DCM_bROE_ENABLED == STD_ON)
  /*! Else if u8IdContext is of a periodic tx */
  else if(u8IdContext == (Dcm_IdContextType)1)
  {
    /*! Raise the cancel bit of the Roe protocol */
    Dsl_strRoeProt.udtMsgContext.msgAddInfo.cancelOperation = TRUE;
  }
  #endif
  #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
  #if(DCM_bROE_ENABLED == STD_ON)
  else if(u8IdContext <= (Dcm_IdContextType)(DCM_u8MAX_NUM_PERIODIC_TX + 1))
  #else
  else if(u8IdContext <= DCM_u8MAX_NUM_PERIODIC_TX)
  #endif
  {
    /*! Raise cancel bit of the corresponding periodic protocol context  */
    #if(DCM_bROE_ENABLED == STD_ON)
    Dsl_astrPeriodicProt[u8IdContext-2].udtMsgContext.msgAddInfo.
    cancelOperation = TRUE;
    #else
    Dsl_astrPeriodicProt[u8IdContext-1].udtMsgContext.msgAddInfo.
    cancelOperation = TRUE;
    #endif
  }
  #endif
  else
  {
    /*! Do nothing. */
  }
}
/******************************************************************************/
/*! \Description Initiates the transmission of a new page.
 *  \param[in]   idContext Context Id \n
 *  \Range       0..255 \n
 *  \param[in]   FilledPageLen Page Length to be transmitted \n
 *  \Range       0..255 \n
    \Trace_To    CDD-DSL-0042(0), CDD-DSL-0066(0), CDD-DSL-0067(0)
*******************************************************************************/
/* Dcm028 */
FUNC(void, DCM_CODE) DslInternal_ProcessPage(Dcm_IdContextType idContext,
                                             Dcm_MsgLenType FilledPageLen)
{
  /*! If the Context Id is of the main protocol */
  if(idContext == DspInternal_u8DSL_MAIN_PROT_CONTEXT)
  {
    vidMainProcessPage(FilledPageLen);
  }
#if(DCM_bROE_ENABLED == STD_ON)
  /*! Else if u8IdContext is of a periodic tx */
  else if(idContext == (Dcm_IdContextType)1)
  {
    vidRoeProcessPage(FilledPageLen);
  }
#endif
#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
#if(DCM_bROE_ENABLED == STD_ON)
  else if(idContext <= (Dcm_IdContextType)(DCM_u8MAX_NUM_PERIODIC_TX + 1))
#else
  else if(idContext <= DCM_u8MAX_NUM_PERIODIC_TX)
#endif
  {
    vidPeriodicProcessPage(idContext, FilledPageLen);
  }
#endif
  else
  {
    /*! Do nothing. */
  }
}
#endif /* DCM_PAGED_BUFFER_ENABLED == STD_ON */

#if(DCM_bROE_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description This API executes the processing of one event, requested \n
 *               internally in the DCM
 *  \param[in]   MsgPtr Message Pointer \n
 *  \Range       Not Null \n
 *  \param[in]   MsgLen Message Length \n
 *  \Range       Range of Dcm_MsgLenType \n
 *  \param[in]   DcmRxPduId Rx PduId \n
 *  \Range       0..255 \n
    \return      Roe internal request acceptance status.
    \Trace_To    CDD-DSL-0034(0), CDD-0838(0), CDD-0846(0), CDD-0898(0),
                 CDD-1566(0), CDD-0183(0), CDD-DSL-0041(0), CDD-DSL-0053(0),
                 CDD-DSL-0054(0), CDD-DSL-0055(0)
*******************************************************************************/
/* Dcm595 */
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
FUNC(Dcm_StatusType, DCM_CODE) DslInternal_ResponseOnOneEvent(
    Dcm_MsgLenType    MsgLen,
    PduIdType         DcmRxPduId,
    boolean           bQueued)
#else
FUNC(Dcm_StatusType, DCM_CODE) DslInternal_ResponseOnOneEvent(
    Dcm_MsgLenType    MsgLen,
    PduIdType         DcmRxPduId)
#endif
{
  CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,AUTOMATIC)
                      LOC_kpstrRoeMsgContext = &Dsl_strRoeProt.udtMsgContext;
  uint8               u8RoeTxBufferId    = (uint8)0;
  uint8               u8RoeRxBufferId    = (uint8)0;
  uint8               u8ConnRef;
  uint8               u8RoeProtIdx;
  uint8               u8RoeTransType;
  #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
  uint8               u8PeriodicProtIdx;
  uint8               u8PeriodicTransType = DCM_PROTOCOL_TYPE1;
  #endif
  boolean             bForwardRequest = FALSE;
  Dcm_StatusType      udtReturn = DCM_E_OK;

  /* Dcm149, Dcm154, Dcm159, Dcm162, Dcm133, Dcm134, Dcm135, Dcm136 */
  u8ConnRef = u8CONN_REF(DcmRxPduId);

  /*! If the ROE container connected to the main protocol PduId is not Null */
  if(pkstrROE_PTR(Dsl_u8MainProtocolIndex, u8ConnRef)
                                       != (Dcm_DslResponseOnEventType*)NULL_PTR)
  {
    /*! Get the ROE Protocol Index */
    u8RoeProtIdx = u8ROE_PROT_IDX(Dsl_u8MainProtocolIndex, u8ConnRef);
    /*! Get the ROE Protocol TransType */
    u8RoeTransType = u8PROT_TRANS_TYPE(u8RoeProtIdx);

    #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
    /*! If the Periodic Protocol container connected to the main protocol PduId
     *  is not Null */
    if(pkstrPERIODIC_TRANS_PTR(Dsl_u8MainProtocolIndex, u8ConnRef)
                                  != (Dcm_DslPeriodicTransmissionType*)NULL_PTR)
    {
      /*! Get the Periodic Protocol Index */
      u8PeriodicProtIdx = u8PERIODIC_PROT_IDX(Dsl_u8MainProtocolIndex,
                                              u8ConnRef);
      /*! Get the Periodic Protocol TransType */
      u8PeriodicTransType = u8PROT_TRANS_TYPE(u8PeriodicProtIdx);
    }
    #endif

    /*! If the Roe Protocol status is IDLE */
    if(Dsl_strRoeProt.udtProtStatus == u8ST_ROE_PROT_IDLE)
    {
      /*! If the Roe protocol TransType is TYPE1 */
      if(u8RoeTransType == DCM_PROTOCOL_TYPE1)
      {
        #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
        /*! If there is no TYPE1 periodic transmission active */
        if((pkstrPERIODIC_TRANS_PTR(Dsl_u8MainProtocolIndex, u8ConnRef) ==
                                     (Dcm_DslPeriodicTransmissionType*)NULL_PTR)
         ||(!((Dsl_astrPeriodicProt[0].udtProtStatus != u8ST_PERIODIC_PROT_IDLE)
            &&(u8PeriodicTransType == DCM_PROTOCOL_TYPE1))))
        {
        #endif
          /*! If main protocol status is IDLE */
          if(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_IDLE)
          {
            /*! Set the Forward flag */
            bForwardRequest = TRUE;
            /*! Get the RX/TX buffer Id's */
            u8RoeTxBufferId = u8TX_BUFFER_ID(u8RoeProtIdx);
            u8RoeRxBufferId = u8RX_BUFFER_ID(u8RoeProtIdx);
          }
          /*! Else if the main protocol status is not IDLE */
          else /* Dcm129 */
          {
            /*! Set the Roe protocol status to PENDING to be processed later
             *  when the main protocol status turns to IDLE */
            Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_PROCESS_PENDING;
            #if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
            /*! Set Dsl_strRoeProt.bIsQueued with bQueued */
            Dsl_strRoeProt.bIsQueued = bQueued;
            #endif
            /*! Set Dsl_strRoeProt.udtMsgContext.reqDataLen with MsgLen */
            Dsl_strRoeProt.udtMsgContext.reqDataLen = MsgLen;
          }
        #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
        }
        /*! Else */
        else
        {
          /*! Return DCM_E_ROE_NOT_ACCEPTED */
          udtReturn = DCM_E_ROE_NOT_ACCEPTED;
        }
        #endif
      }
      /*! Else if the Roe protocol TransType is TYPE2 */
      else
      {
        /*! Set the Forward flag */
        bForwardRequest = TRUE;
        /*! Get the RX/TX buffer Id's */
        u8RoeTxBufferId = u8TX_BUFFER_ID(u8RoeProtIdx);
        u8RoeRxBufferId = u8RX_BUFFER_ID(u8RoeProtIdx);
      }
    }
    /*! Else if the Roe Protocol status is not IDLE */
    else
    {
      /*! Return DCM_E_ROE_NOT_ACCEPTED */
      udtReturn = DCM_E_ROE_NOT_ACCEPTED;
    }

    /*! If the return value is OK */
    if(udtReturn == DCM_E_OK)
    {
      /*! If the Forward flag is set */
      if(bForwardRequest == TRUE)
      {
        /*! Prepare the Roe Message Context */
        LOC_kpstrRoeMsgContext->reqData =
            Dcm_kstreDslConfig.astrDcmDslBuffer[u8RoeRxBufferId].pudtBuffer;
        LOC_kpstrRoeMsgContext->reqDataLen = MsgLen;
        LOC_kpstrRoeMsgContext->resData =
            Dcm_kstreDslConfig.astrDcmDslBuffer[u8RoeTxBufferId].pudtBuffer;
        LOC_kpstrRoeMsgContext->resMaxDataLen =
            Dcm_kstreDslConfig.astrDcmDslBuffer[u8RoeTxBufferId].udtBufferSize;
        LOC_kpstrRoeMsgContext->dcmRxPduId = DcmRxPduId;
        LOC_kpstrRoeMsgContext->idContext = (Dcm_IdContextType)1;
        LOC_kpstrRoeMsgContext->msgAddInfo.reqType =
          (u8RX_ADDR_TYPE(DcmRxPduId) == DCM_PHYS_ADDR)? FALSE : TRUE;
        LOC_kpstrRoeMsgContext->msgAddInfo.cancelOperation = FALSE;

        /*! Set the Roe Protocol status to PROCESSING */
        Dsl_strRoeProt.udtProtStatus = u8ST_ROE_PROT_PROCESSING;
        Dsl_strRoeProt.u8RoeProtIndex = u8RoeProtIdx;

        /*! Lock the Roe buffers. */
        /* Dcm195 */
        Dsl_astrBufferInfo[u8RoeTxBufferId].udtStatus = u8ST_BUFF_LOCKED;
        Dsl_astrBufferInfo[u8RoeRxBufferId].udtStatus = u8ST_BUFF_LOCKED;
        /*! Call DsdInternal_DataIndication() to forward the request to DSD */
        DsdInternal_DataIndication(LOC_kpstrRoeMsgContext,
                                   u8SID_TABLE(u8RoeProtIdx));
      }
    }
  }
  /*! Else if the ROE container connected to the main protocol PduId is Null */
  else
  {
    /*! Return DCM_E_ROE_NOT_ACCEPTED */
    udtReturn = DCM_E_ROE_NOT_ACCEPTED;
  }
  
  return (udtReturn);
}
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description
    \param[out]  \n
    \Range \n
    \Unit
    \return
    \Trace_To  CDD-0827(0), CDD-0830(0), CDD-0831(0),
               CDD-0898(0), CDD-1567(0), CDD-DSL-0060(0), CDD-DSL-0061(0),
               CDD-DSL-0063(0), CDD-DSL-0062(0)
*******************************************************************************/
/* !Deviation : Inhibit MISRA rule [4700]: Metrics threshold is violated
 *              for a better readability  */
/* PRQA S 4700 ++ */
FUNC(Dcm_StatusType, DCM_CODE) DslInternal_ResponseOnOneDataByPeriodicId(
    uint8 u8PeriodicId)
{
  Dcm_MsgContextType* pstrPeriodicMsgContext =
      &Dsl_astrPeriodicProt[0].udtMsgContext;
  uint8               u8PeriodicTxBufferId;
  uint8               u8PeriodicRxBufferId;
  uint8               u8ConnRef;
  uint8               u8PeriodicProtIdx;
  uint8               u8PeriodicTransType;
#if(DCM_bROE_ENABLED == STD_ON)
  uint8               u8RoeProtIdx;
  uint8               u8RoeTransType = DCM_PROTOCOL_TYPE1;
#endif
  uint8               u8PeriodicReqBuffPtr;
  uint8               u8PeriodicProtArrIdx = (uint8)0;
  uint8*              pu8RxBufferPtr =
      Dcm_kstreDslConfig.astrDcmDslBuffer[0].pudtBuffer;
  boolean             bForwardRequest  = FALSE;
  uint32              u32TxBufferQuota = (uint32)0;
  Dcm_StatusType      udtReturn = DCM_E_OK;

  /* Dcm150, Dcm155, Dcm160, Dcm162, Dcm123, Dcm125, Dcm126 */
  /*! Get the connection reference of the main protocol RxPduId */
  u8ConnRef = u8CONN_REF(Dsl_udtMainProtRxPduId);

  /*! If the Periodic Transmission container attached to the current main
   *  protocol exists */
  if(pkstrPERIODIC_TRANS_PTR(Dsl_u8MainProtocolIndex,u8ConnRef)
      != (Dcm_DslPeriodicTransmissionType*)NULL_PTR)
  {
    /*! Get the Periodic Protocol index. */
    u8PeriodicProtIdx = u8PERIODIC_PROT_IDX(Dsl_u8MainProtocolIndex, u8ConnRef);
    /*! Get the periodic protocol TransType */
    u8PeriodicTransType = u8PROT_TRANS_TYPE(u8PeriodicProtIdx);

    /*! IF the ROE is Enabled */
    #if(DCM_bROE_ENABLED == STD_ON)
    /*! Get the ROE container pointer */
    if(pkstrROE_PTR(Dsl_u8MainProtocolIndex,u8ConnRef) !=
        (Dcm_DslResponseOnEventType*)NULL_PTR)
    {
      /*! Get the Roe protocol index */
      u8RoeProtIdx = u8ROE_PROT_IDX(Dsl_u8MainProtocolIndex, u8ConnRef);
      /*! Get the Roe protocol TransType */
      u8RoeTransType = u8PROT_TRANS_TYPE(u8RoeProtIdx);
    }
    #endif

    /*! Get the periodic protocol RX/TX Buffer Id's */
    u8PeriodicRxBufferId = u8RX_BUFFER_ID(u8PeriodicProtIdx);
    u8PeriodicTxBufferId = u8TX_BUFFER_ID(u8PeriodicProtIdx);

    /*! If the periodic protocol TransType is TYPE1 */
    if(u8PeriodicTransType == DCM_PROTOCOL_TYPE1)
    {
      /*! If the periodic protocol status is IDLE */
      if(Dsl_astrPeriodicProt[0].udtProtStatus == u8ST_PERIODIC_PROT_IDLE)
      {
        /*! IF the ROE is enabled */
        #if(DCM_bROE_ENABLED == STD_ON)
        /*! If the ROE container does not exist, or not of (the Roe protocol
         *  status is not IDLE and Roe protocol TransType is TYPE1) */
        if((pkstrROE_PTR(Dsl_u8MainProtocolIndex,u8ConnRef) ==
            (Dcm_DslResponseOnEventType*)NULL_PTR)
         ||(!((Dsl_strRoeProt.udtProtStatus != u8ST_ROE_PROT_IDLE)
            &&(u8RoeTransType == DCM_PROTOCOL_TYPE1))))
        {
        #endif

          /*! If the main protocol status is IDLE */
          if(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_IDLE)
          {
            /*! Set 1st byte of the periodic protocol RX buffer with 0x22 */
            Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicRxBufferId].
            pudtBuffer[0] = 0x22;
            /*! Set 2nd byte of the periodic protocol RX buffer with 0xF2 */
            Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicRxBufferId].
            pudtBuffer[1] = 0xF2;
            /*! Set 3rd byte of the periodic protocol RX buffer with
             *  u8PeriodicId */
            Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicRxBufferId].
            pudtBuffer[2] = u8PeriodicId;

            /*! Set the Forward Request flag */
            bForwardRequest = TRUE;
            /*! Set the Periodic TX Index to 0 */
            u8PeriodicProtArrIdx = 0;
            /*! Get a pointer to the periodic protocol RX buffer */
            pu8RxBufferPtr  = Dcm_kstreDslConfig.
                              astrDcmDslBuffer[u8PeriodicRxBufferId].
                              pudtBuffer;
            /*! Get the TX buffer Quota as the total size of the periodic TX
             *  buffer */
            u32TxBufferQuota = Dcm_kstreDslConfig.
                               astrDcmDslBuffer[u8PeriodicTxBufferId].
                               udtBufferSize;
          }
          /*! Else if the main protocol status is not IDLE */
          else /* Dcm121 */
          {
            /*! Set the periodic protocol status to PROCESS_PENDING */
            Dsl_astrPeriodicProt[0].udtProtStatus =
                                             u8ST_PERIODIC_PROT_PROCESS_PENDING;
            Dsl_u8PendingPeriodicId = u8PeriodicId;
          }
#if(DCM_bROE_ENABLED == STD_ON)
        }
        /*! Else */
        else
        {
          /*! Return DCM_E_PERIODICID_NOT_ACCEPTED */
          udtReturn = DCM_E_PERIODICID_NOT_ACCEPTED;
        }
#endif
      }
      /*! Else if the periodic protocol status is not IDLE */
      else
      {
        /*! Return DCM_E_PERIODICID_NOT_ACCEPTED */
        udtReturn = DCM_E_PERIODICID_NOT_ACCEPTED;
      }
    }
    /*! Else if the periodic protocol TransType is TYPE2 */
    else
    {
      /*! If there is a free periodic TX channel */
      /* !Deviation : Inhibit MISRA rule [3416]: function call is used in
       *              conditional statement for better readability            */
      /* PRQA S 3416 ++                                                       */
      if(udtGetFreePeriodicTxIdx(&u8PeriodicProtArrIdx) == E_OK)
      {
        /* PRQA S 3416 --                                                     */
        /*! Set the Forward Request flag. */
        bForwardRequest = TRUE;

        /*! Set the RX buffer pointer to point at the periodic RX buffer at the
         *  index equal to the periodic TX index multiplied by 3 */
        u8PeriodicReqBuffPtr = (uint8)(u8PeriodicProtArrIdx * 3);
        pu8RxBufferPtr = &Dcm_kstreDslConfig.
                         astrDcmDslBuffer[u8PeriodicRxBufferId].
                         pudtBuffer[u8PeriodicReqBuffPtr];
        /*! Get a pointer to the periodic protocol message context. */
        pstrPeriodicMsgContext = &Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].
                                 udtMsgContext;
        /*! Set the 3 bytes of the periodic RX buffer starting at
         *  u8PeriodicTxIdx*3 with 0x22, 0xF2, u8PeriodicId respectively. */
        pu8RxBufferPtr[0] = 0x22;
        pu8RxBufferPtr[1] = 0xF2;
        pu8RxBufferPtr[2] = u8PeriodicId;
        /*! Get the TX buffer Quota as the periodic TX buffer size divided by
         *  DCM_u8MAX_NUM_PERIODIC_TX */
        u32TxBufferQuota = Dcm_kstreDslConfig.
            astrDcmDslBuffer[u8PeriodicTxBufferId].
            udtBufferSize/DCM_u8MAX_NUM_PERIODIC_TX;
      }
      /*! Else if there is no free periodic TX channel */
      else
      {
        /*! Return DCM_E_PERIODICID_NOT_ACCEPTED */
        udtReturn = DCM_E_PERIODICID_NOT_ACCEPTED;
      }
    }

    /*! If the return value is DCM_E_OK */
    if(udtReturn == DCM_E_OK)
    {
      /*! If the Forward Request is set */
      if(bForwardRequest == TRUE)
      {
        /*! Fill the periodic message context */
        pstrPeriodicMsgContext->reqData            = pu8RxBufferPtr;
        pstrPeriodicMsgContext->reqDataLen         = 3;
        pstrPeriodicMsgContext->resData            =
            &Dcm_kstreDslConfig.astrDcmDslBuffer[u8PeriodicTxBufferId].
            pudtBuffer[u8PeriodicProtArrIdx*u32TxBufferQuota];
        pstrPeriodicMsgContext->resMaxDataLen      = u32TxBufferQuota;
        pstrPeriodicMsgContext->dcmRxPduId         = Dsl_udtMainProtRxPduId;
#if(DCM_bROE_ENABLED == STD_ON)
        pstrPeriodicMsgContext->idContext          =
            (Dcm_IdContextType)(u8PeriodicProtArrIdx + 2);
#else
        pstrPeriodicMsgContext->idContext          =
            (Dcm_IdContextType)(u8PeriodicProtArrIdx + 1);
#endif
        pstrPeriodicMsgContext->msgAddInfo.reqType =
          (u8RX_ADDR_TYPE(Dsl_udtMainProtRxPduId) == DCM_PHYS_ADDR) ?
              FALSE : TRUE;
        pstrPeriodicMsgContext->msgAddInfo.cancelOperation = FALSE;

        /*! Set the periodic protocol status to PROCESSING */
        Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].udtProtStatus =
            u8ST_PERIODIC_PROT_PROCESSING;
        Dsl_astrPeriodicProt[u8PeriodicProtArrIdx].u8PeriodicProtIndex =
            u8PeriodicProtIdx;

        /*! Lock the periodic protocol TX and RX buffers */
        Dsl_astrBufferInfo[u8PeriodicRxBufferId].udtStatus = u8ST_BUFF_LOCKED;
        Dsl_astrBufferInfo[u8PeriodicTxBufferId].udtStatus = u8ST_BUFF_LOCKED;
        /* Dcm195 */
        /*! Call DsdInternal_DataIndication() to forward the request to DSD */
        DsdInternal_DataIndication(pstrPeriodicMsgContext,
                                   u8SID_TABLE(u8PeriodicProtIdx));
      }
    }
  }
  /*! Else */
  else
  {
    /*! Return DCM_E_PERIODICID_NOT_ACCEPTED */
    udtReturn = DCM_E_PERIODICID_NOT_ACCEPTED;
  }

  return (udtReturn);
}
/* PRQA S 4700 -- */
#endif

#if((DCM_bROE_ENABLED == STD_ON) && (DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON))
/******************************************************************************/
/*! \Description Clear Roe Queue
    \Trace_To    CDD-DSL-0036(0)
*******************************************************************************/
/* Dcm613 */
FUNC(void, DCM_CODE) DslInternal_vidClearRoeTxQueue(void)
{
  /*! Set Dsl_u16RoeQueRear to DCM_u16DSP_ROE_MAX_QUEUE_LENGTH */
  Dsl_u16RoeQueRear  = DCM_u16DSP_ROE_MAX_QUEUE_LENGTH;
  /*! Set Dsl_u16RoeQueFront to DCM_u16DSP_ROE_MAX_QUEUE_LENGTH */
  Dsl_u16RoeQueFront = DCM_u16DSP_ROE_MAX_QUEUE_LENGTH;
}
#endif

/******************************************************************************/
/*! \Description Sends Forced RCRRP \n
    \param[in]   Id Context \n
    \Range       0 \n
    \return      void \n
    \Trace_To    CDD-DSL-0017(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DslInternal_vidForceRCRRP(Dcm_IdContextType udtIdContext)
{
  /*! If udtIdContext is the Main Protocol IdContext and main protocol status
   *  is PROCESSING and no Forced RCRRP TX in progress */
  if((udtIdContext == DspInternal_u8DSL_MAIN_PROT_CONTEXT)
   &&(Dsl_u8MainProtocolStatus == u8ST_MN_PROT_PROCESSING)
   &&(Dsl_bFrcdRCRRPInProgress == FALSE))
  {
    /*! If no Internal TX is in progress */
    if(Dsl_bIntTxInProgress == FALSE)
    {
      /*! If Max Number of RespPend is not 0xFF and the number of sent RespPend
       *  is less than the maximum configured, increment RespPendCount */
      if((Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslDiagRespMaxNumRespPend
          != (uint8)0xFF)
        &&(Dsl_u8RespPendCount <
          Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslDiagRespMaxNumRespPend))
      {
        Dsl_u8RespPendCount++;
      }

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be          */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Enter_Dcm_Access_051();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be          */
      /*              implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /* PRQA S 3138 ++                                                       */
      SchM_Enter_Dcm_Access_056();
      /* PRQA S 3138 --                                                       */
      /* PRQA S 3141 --                                                       */

      /*! If ReponsePendCount is less than the configured Max, or Max is 0xFF or
       *  there is a cancellation in progress */
      if((Dsl_u8RespPendCount <
          Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslDiagRespMaxNumRespPend)
       ||(Dcm_pkstrePbConfig->strPbDcmDslConfig.u8DcmDslDiagRespMaxNumRespPend==
          (uint8)0xFF)
       || (Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation == TRUE))
      {
        /*! Reload P2Counter & P2Adjust */
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Enter_Dcm_Access_055();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */
        Dsl_u16P2Counter = Dsl_u16P2StarReload;
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_Dcm_Access_055();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */

        Dsl_u16P2Adjust = u16P2STAR_SERVER_ADJUST(Dsl_u8MainProtocolIndex);

        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_Dcm_Access_056();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */

        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be   */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_Dcm_Access_051();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */

        /*! If no Internal TX In Progress and Response Pending NRC is allowed
         *  for the current service */
        /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used
         *              in conditional statement for better readability       */
        /* PRQA S 3415 ++                                                     */
        /* PRQA S 3416 ++                                                     */
        if(udtNrcResponsePendAllowed() == E_OK)
        {
          /* PRQA S 3415 --                                                   */
          /* PRQA S 3416 --                                                   */
          /* Dcm165 */
          /*! Call vidSendForcedNrcResponsePend() */
          vidSendForcedNrcResponsePend();
        }
      }
      /*! Else */
      /* Dcm120 */
      else
      {
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_Dcm_Access_056();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */

        /*! Set Cancel Bit of Main Prot Context*/
        Dsl_strMainProtMsgContext.msgAddInfo.cancelOperation = TRUE;
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Enter_Dcm_Access_055();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */
        /*! Reload the P2Counter with P2Star value */
        Dsl_u16P2Counter = Dsl_u16P2StarReload;
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_Dcm_Access_055();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */
        /*! Reload the P2Adjust */
        Dsl_u16P2Adjust = u16P2STAR_SERVER_ADJUST(Dsl_u8MainProtocolIndex);

        /*! If no Internal TX In Progress and Response Pending NRC is allowed
         *  for the current service */
        /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used
         *              in conditional statement for better readability       */
        /* PRQA S 3415 ++                                                     */
        /* PRQA S 3416 ++                                                     */
        if(udtNrcResponsePendAllowed() == E_OK)
        {
          /* PRQA S 3415 --                                                   */
          /* PRQA S 3416 --                                                   */
          /* Dcm165 */
          /*! Call vidSendForcedNrcResponsePend() */
          vidSendForcedNrcResponsePend();
        }

        /*! If General Reject NRC is allowed for the current service */
        /* !Deviation : Inhibit MISRA rule [3415, 3416]: function call is used
         *              conditional statement for better readability          */
        /* PRQA S 3415 ++                                                     */
        /* PRQA S 3416 ++                                                     */
        if(udtNrcGeneralRejectAllowed() == E_OK)
        {
          /* PRQA S 3415 --                                                   */
          /* PRQA S 3416 --                                                   */
          /*! Set Dsl_bGeneralRejectPend */
          Dsl_bGeneralRejectPend = TRUE;
        }

        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be   */
        /*              implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /* PRQA S 3138 ++                                                     */
        SchM_Exit_Dcm_Access_051();
        /* PRQA S 3138 --                                                     */
        /* PRQA S 3141 --                                                     */
      }
    }
  }
}
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */
/*              for memory allocation and should be included several times.  */
/* PRQA S 5087,0838 L1 */
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */

/** \} */ /* end of DSL module group */
/** \} */ /* end of DSL Component group */

/*-------------------------------- end of file -------------------------------*/
